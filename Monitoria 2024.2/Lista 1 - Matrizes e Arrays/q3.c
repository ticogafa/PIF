
//1187 - Área Superior

#include <stdio.h>
#include <string.h>

int main ()
{
    int inicio = 1, fim = 10, lin, col, cont = 0;
    char op;
    double matriz[12][12], acc = 0;

    scanf("%c", &op);

    for (lin = 0; lin < 12; lin++)
        for (col = 0; col < 12; col++)
            scanf("%lf", &matriz[lin][col]);

    for (lin = 0; lin < 5; lin++)
    {
        for (col = inicio; col <= fim; col++)
        {
            acc += matriz[lin][col];
            cont++;
        }
        inicio++;
        fim--;
    }

    if (op == 'S')
        printf("%.1lf\n", acc);
    else if (op == 'M')
    {
        acc /= cont;
        printf("%.1lf\n", acc);
    }

    return 0;
}