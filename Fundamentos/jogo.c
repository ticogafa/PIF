#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>

#define GAME_LOOP_DIVISOR 12

struct player_data {
    unsigned int x;
    unsigned int y;
    unsigned int score;
    bool ai;
};

struct ball_data {
    unsigned int x;
    unsigned int y;
    bool mv_left;
    bool mv_right;
    bool mv_up;
    bool mv_down;
};

struct game_data {
    unsigned int max_field_x; /* field size x */
    unsigned int max_field_y; /* field size y */
    time_t time_played;
    struct player_data *p1; /* Player 1 */
    struct player_data *p2; /* Player 2 */
    struct ball_data *ball; /* Ball */
};


/* Clears the last line of the terminal */
static void clear_statusbar(unsigned int y,
        unsigned int x) {
    unsigned int i;

    for (i = 0; i <= x; i++) {
        mvaddch(y, i, ' ');
    }
}


/* Draws the statusbar */
void draw_statusbar(struct game_data *gd) {
    clear_statusbar(gd->max_field_y,
            gd->max_field_x);

    mvprintw(gd->max_field_y, 0,
            "%02d", gd->p1->score);
    mvprintw(gd->max_field_y,
            (gd->max_field_x/2)-10,"%04d seconds played",
            time(NULL) - gd->time_played);
    mvprintw(gd->max_field_y,
            gd->max_field_x-1,
            "%02d", gd->p2->score);
}


/* Called in the main loop to verify the size
 * of the current game field and if it changed
 * to update the size.
 */
bool check_field_size(struct game_data *gd) {
    unsigned int y, x; /* temporary data */
    if (gd == NULL) {
        return false;
    }

    /* Get current size of the terminal */
    getmaxyx(stdscr, y, x);

    x--;
    y--;

    /* If size changed, update the data and return false so
     * it's easy to check if the data changed.
     */
    if ((gd->max_field_y != y) ||
            (gd->max_field_x != x)) {

        clear_statusbar(gd->max_field_y,
                gd->max_field_x);

        gd->max_field_x = x;
        gd->max_field_y = y;

        return false;
    }

    return true;
}


/* Allocates memory for every item and
 * fills them with the initial data.
 */
struct game_data *init_game_data(void) {
    struct game_data *gd;

    /* Allocate memory for every item */
    gd = malloc(sizeof(struct game_data));
    if (gd == NULL) {
        return NULL;
    }

    gd->p1 = malloc(sizeof(struct player_data));
    if (gd->p1 == NULL) {
        free(gd);
        return NULL;
    }

    gd->p2 = malloc(sizeof(struct player_data));
    if (gd->p2 == NULL) {
        free(gd->p1);
        free(gd);
        return NULL;
    }

    gd->ball = malloc(sizeof(struct ball_data));
    if (gd->ball == NULL) {
        free(gd->p2);
        free(gd->p1);
        free(gd);
        return NULL;
    }

    /* Fill items with the default data */
    check_field_size(gd);

    time(&gd->time_played);

    gd->p1->x = 0;
    gd->p1->y = gd->max_field_y / 2;
    gd->p1->score = 0;
    gd->p1->ai = false;

    gd->p2->x = gd->max_field_x;
    gd->p2->y = gd->max_field_y / 2;
    gd->p2->score = 0;
    gd->p2->ai = true;

    gd->ball->x = gd->max_field_x / 2;
    gd->ball->y = (gd->max_field_y-1) / 2; /* w/o statusbar */
    gd->ball->mv_left = false;
    gd->ball->mv_right = false;
    gd->ball->mv_up = false;
    gd->ball->mv_down = false;

    return gd;
}


/* Controls the movement of the ball */
void ball_movement(struct game_data *gd) {
    if (gd == NULL) {
        return;
    }

    /* Clear current position of the ball */
    mvaddch(gd->ball->y, gd->ball->x, ' ');

    /* If the terminal was resized, place ball to
     * the center of the terminal.
     */
    if (!check_field_size(gd)) {
        gd->ball->y = gd->max_field_y / 2;
        gd->ball->x = gd->max_field_x / 2;
    }

    if (gd->ball->x == 1) {
        /* Does it hit p1s pad? */
        if ((gd->ball->y > gd->p1->y-3) &&
                (gd->ball->y < gd->p1->y+3)) {
            gd->ball->mv_left = false;
            gd->ball->mv_right = true;
            gd->ball->mv_up = false;
            gd->ball->mv_down = false;

            if ((gd->ball->y > gd->p1->y-3) &&
                    (gd->ball->y < gd->p1->y)) {
                gd->ball->mv_up = true;
            }
            if ((gd->ball->y > gd->p1->y) &&
                    (gd->ball->y < gd->p1->y+3)) {
                gd->ball->mv_down = true;
            }
        }
    }

    if (gd->ball->x == gd->max_field_x-1) {
        /* Does it hit p2s pad? */
        if ((gd->ball->y > gd->p2->y-3) &&
                (gd->ball->y < gd->p2->y+3)) {
            gd->ball->mv_left = true;
            gd->ball->mv_right = false;
            gd->ball->mv_up = false;
            gd->ball->mv_down = false;

            if ((gd->ball->y > gd->p2->y-3) &&
                    (gd->ball->y < gd->p2->y)) {
                gd->ball->mv_up = true;
            }
            if ((gd->ball->y > gd->p2->y) &&
                    (gd->ball->y < gd->p2->y+3)) {
                gd->ball->mv_down = true;
            }
        }
    }

    /* Check if it hits the top of the terminal */
    if (gd->ball->y == 0) {
        gd->ball->mv_up = false;
        gd->ball->mv_down = true;
    }
    /* Check if it hits the statusbar */
    else if (gd->ball->y == gd->max_field_y-1) {
        gd->ball->mv_down = false;
        gd->ball->mv_up = true;
    }


    /* Check if p2 scores and if, reset location to the front of
     * p1s pad launching the ball will be handled elsewhere.
     */
    if (gd->ball->x == 0) {
        gd->p2->score +=1 ;

        gd->ball->x = 1;
        gd->ball->y = (gd->max_field_y-1) / 2;
        gd->ball->mv_left = false;
        gd->ball->mv_right = false;
        gd->ball->mv_up = false;
        gd->ball->mv_down = false;
    }
    /* Check if p1 scores and if, reset the location to the front of
     * p2s pad, launching the ball will be handled elsewhere.
     */
    if (gd->ball->x == gd->max_field_x) {
        gd->p1->score +=1 ;

        gd->ball->x = gd->max_field_x-1;
        gd->ball->y = (gd->max_field_y-1) / 2;
        gd->ball->mv_left = false;
        gd->ball->mv_right = false;
        gd->ball->mv_up = false;
        gd->ball->mv_down = false;
    }

    /* Movement of the ball */
    if (gd->ball->mv_left == true) {
        gd->ball->x--;
    }
    else if (gd->ball->mv_right == true) {
        gd->ball->x++;
    }
    if (gd->ball->mv_up == true) {
        gd->ball->y--;
    }
    else if (gd->ball->mv_down == true) {
        gd->ball->y++;
    }
    mvaddch(gd->ball->y, gd->ball->x, '0');
}


/* Handles the launch when a player scored */
void ball_launch(struct game_data *gd) {
    int c;
    struct player_data *p;

    if (gd == NULL) {
        return;
    }

    p = (gd->ball->x == 1) ? gd->p1 : gd->p2;

    mvaddch(p->y-2, 0, ' ');
    mvaddch(p->y-1, 0, ' ');
    mvaddch(p->y, 0, ' ');
    mvaddch(p->y+1, 0, ' ');
    mvaddch(p->y+2, 0, ' ');

    p->y = gd->ball->y;

    /* Check if it's the turn of the player,
     * if so, let him move his pad.
     */
    if (p->x == 0) {
        while ((c = getch()) != ' ') {
            mvaddch(p->y-2, 0, ' ');
            mvaddch(p->y-1, 0, ' ');
            mvaddch(p->y, 0, ' ');
            mvaddch(p->y+1, 0, ' ');
            mvaddch(p->y+2, 0, ' ');

            if ((c == KEY_UP) &&
                  (p->y > gd->ball->y-3) &&
                  (p->y < gd->ball->y+3)) {
                p->y--;
            }
            else if ((c == KEY_DOWN) &&
                  (p->y > gd->ball->y-3) &&
                  (p->y < gd->ball->y+3)) {
                p->y++;
            }
            mvaddch(p->y-2, 0, '|');
            mvaddch(p->y-1, 0, '|');
            mvaddch(p->y, 0, '|');
            mvaddch(p->y+1, 0, '|');
            mvaddch(p->y+2, 0, '|');
        }
    }
    else {
        p->y += rand()%3 - 1;
    }
}


/* Controls the pad of p2 */
void p2_ai(struct game_data *gd) {
    if (gd == NULL) {
        return;
    }

    /* Clear current position of the pad */
    mvaddch(gd->p2->y-2, gd->p2->x, ' ');
    mvaddch(gd->p2->y-1, gd->p2->x, ' ');
    mvaddch(gd->p2->y, gd->p2->x, ' ');
    mvaddch(gd->p2->y+1, gd->p2->x, ' ');
    mvaddch(gd->p2->y+2, gd->p2->x, ' ');

    /* Correct the position if the size of the terminal was changed */
    gd->p2->x = gd->max_field_x;
    while ((gd->p2->y+3) > (gd->max_field_y-1)) {
        gd->p2->y--;
    }

    /* If that's too hard, add a if ((rand()%3)==1) or so at this point */
    if ((gd->ball->y > gd->p2->y+3) &&
           (gd->p2->y+3 < gd->max_field_y-1)) {
        gd->p2->y++;
    }
    else if ((gd->ball->y < gd->p2->y-3) &&
            (gd->p2->y-3 > 0)) {
        gd->p2->y--;
    }

    /* Draw pad */
    mvaddch(gd->p2->y-2, gd->p2->x, '|');
    mvaddch(gd->p2->y-1, gd->p2->x, '|');
    mvaddch(gd->p2->y, gd->p2->x, '|');
    mvaddch(gd->p2->y+1, gd->p2->x, '|');
    mvaddch(gd->p2->y+2, gd->p2->x, '|');
}


/* Handles the game, so that the game is seperated from
 * the ncurses handling in the main function.
 */
int game(void) {
    int p, /* Time for player input y/n? */
        player_input,
        r; /* return value */
    struct game_data *gd; /* contains all our data */

    if ((gd = init_game_data()) == NULL) {
        mvprintw(0, 0, "Could not allocate memory for the game_data.");
        timeout(-1);
        getch();
        return -1;
    }

    p=0;
    gd->ball->mv_right = true;

    timeout(0); /* set delay non blocking */

    mvaddch(gd->p1->y-2, 0, '|');
    mvaddch(gd->p1->y-1, 0, '|');
    mvaddch(gd->p1->y, 0, '|');
    mvaddch(gd->p1->y+1, 0, '|');
    mvaddch(gd->p1->y+2, 0, '|');
    ball_movement(gd);
    p2_ai(gd);

    refresh();

    while ((gd->p1->score != 21) &&
            (gd->p2->score != 21)) {

        if (p == 4) {

            /* Input Handling for P1 goes here.
             * I don't have the knowledge for
             * a well working one yet, but it
             * should be relatively easy.
             * man 3 ncurses
             * man 3 curs_getch
             * man 3 curs_inopts
             */
            mvaddch(gd->p1->y-2, 0, ' ');
            mvaddch(gd->p1->y-1, 0, ' ');
            mvaddch(gd->p1->y, 0, ' ');
            mvaddch(gd->p1->y+1, 0, ' ');
            mvaddch(gd->p1->y+2, 0, ' ');

            /* Correct the position if the size of
             * the terminal was changed.
             */
            while((gd->p1->y+3) > (gd->max_field_y-1)) {
                gd->p1->y--;
            }

            player_input = getch();
            if ((player_input == KEY_UP) &&
                    ((gd->p1->y-2) > 0)) {
                gd->p1->y--;
            }
            else if ((player_input == KEY_DOWN) &&
                    ((gd->p1->y+2) < (gd->max_field_y-1))) {
                gd->p1->y++;
            }

            mvaddch(gd->p1->y-2, 0, '|');
            mvaddch(gd->p1->y-1, 0, '|');
            mvaddch(gd->p1->y, 0, '|');
            mvaddch(gd->p1->y+1, 0, '|');
            mvaddch(gd->p1->y+2, 0, '|');

            p2_ai(gd);
            p=0;
        }

        ball_movement(gd);
        if ((gd->ball->mv_left == false) &&
                (gd->ball->mv_right == false)) {
                ball_launch(gd);
        }
        check_field_size(gd);
        draw_statusbar(gd);

        p++;
        refresh();
        usleep(1000000 / GAME_LOOP_DIVISOR);
    }

    r = (gd->p1->score == 21) ? 1 : 2;
    clear_statusbar(gd->max_field_y,
            gd->max_field_x);

    free(gd->p1);
    free(gd->p2);
    free(gd->ball);
    free(gd);

    return r;
}


/* Kills the ncurses Window */
void quit(void) {
    endwin();
}


int main(void) {

    int winner, y, x;

    initscr(); /* start the WINDOW */
    atexit(quit);
    clear(); /* Clear Terminal */
    noecho(); /* Don't echo input */
    nonl(); /* Receive \r instead of \n */
    curs_set(0); /* Set Cursor invisible */
    cbreak(); /* No line buffering */
    keypad(stdscr, true); /* Activate keypad */

    srand(time(NULL)); /* Set random seed */

    clear();
    winner = game();
    clear();
    getmaxyx(stdscr, y, x);
    mvprintw(y/2, (x/2)-7, "Player %d wins.", winner);
    timeout(-1); /* Set delay to blocking */
    getch();

    return EXIT_SUCCESS;
}