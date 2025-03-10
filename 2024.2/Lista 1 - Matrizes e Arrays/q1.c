
//1875 - Tribol

#include <stdio.h>

int main() {
    int C; 
    scanf("%d", &C);

    for(int i = 0; i<C; i++) {
        int P; 
        scanf("%d", &P);

        int scores[3] = {0, 0, 0}; 

        for (int i = 0; i < P; i++) {
            char M, S; 
            scanf(" %c %c", &M, &S);

            int teamM, teamS;

            if (M == 'R') teamM = 0;
            else if (M == 'G') teamM = 1;
            else if (M == 'B') teamM = 2;
            else continue;

            if (S == 'R') teamS = 0;
            else if (S == 'G') teamS = 1;
            else if (S == 'B') teamS = 2;
            else continue;

            if ((teamM + 1) % 3 == teamS) { 
                scores[teamM] += 2;
            } else { 
                scores[teamM] += 1;
            }
        }

        if (scores[0] == scores[1] && scores[1] == scores[2]) {
            printf("trempate\n");

        }else if(scores[0]>scores[1] || scores[0]>scores[2] || scores[1]>scores[0] || scores[1]>scores[2]|| scores[2]>scores[0]||scores[2]>scores[1]){
             if((scores[0] == scores[1] && scores[0]>scores[2]) || (scores[1] == scores[2] && scores[1]>scores[0]) || (scores[0] == scores[2] && scores[0]>scores[1])) {
            printf("empate\n");

             }
             else if (scores[0] > scores[1] && scores[0] > scores[2]) {
                printf("red\n");
            } else if (scores[1] > scores[0] && scores[1] > scores[2]) {
                printf("green\n");
            } else {
                printf("blue\n");
            }
        }
         
    }

    return 0;
}