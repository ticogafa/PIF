#include <stdio.h>
#include <stdlib.h>

struct ponto{ //letra A
    float x;
    float y;
};


struct circunferência{ //letra B
    struct ponto centro;
    float raio;
};


int main()
{
    struct ponto *points; //letra C
    int tamanho, count = 0;
    struct circunferência circ;
    float dist;
    
    scanf("%d", &tamanho);
    points = (struct ponto *)malloc(tamanho*sizeof(struct ponto));
    
    for(int i = 0; i<tamanho; i++){
        scanf("%f %f", &points[i].x, &points[i].y);
    }
    
    scanf("%f %f %f", &circ.centro.x, &circ.centro.y, &circ.raio); //letra D
    
    for(int i = 0; i<tamanho; i++){
        dist = sqrt(pow((circ.centro.x - points[i].x),2) + pow((circ.centro.y - points[i].y),2));
        
        if(dist < circ.raio){
            count++;
        }
    }
    
    printf("Pontos Internos: %d",count);
    
    free(points); //letra E
    

    return 0;
}

/*
OBS - Na questão acima coloquei dois for somente por questões didáticas e para separar bem as letras 
C e D. Contudo, os alunos podem sim utilizar o mesmo form para fazer ambas a operações (ou seja, 
preencher o array e calcular as distâncias)
*/



/*

 (STRUTCS E ALOCAÇÃO DINÂMICA DE MEMÓRIA - 2.0 pontos) Considere um plano cartesiano bidimensional 
 contendo vários pontos, cada um deles representados pelas coordenadas x e y em ponto flutuante (float). 
 Dada uma circunferência neste mesmo plano, representada por um ponto (com coordenadas x e y em float) 
 que representa o centro e um float que representa seu raio, desenvolva um programa capaz de, dado um 
 conjunto de pontos e uma circunferência, determinar quantos pontos estão contidos na circunferência. 
 Seu programa deve:

Definir uma struct ponto com as coordenadas x e y (ambos floats); (0.25)

Definir uma struct circunferência, a qual tem um ponto central do tipo struct ponto e um raio (float); (0.25)

Alocar dinamicamente um array de N pontos, sendo N um valor fornecido pelo usuário, e preenchê-lo com dados 
das coordenadas dos pontos, também fornecidos pelo usuário; (0.6)

Dada uma circunferência fornecida pelo usuário (coordenadas x e y do centro e um raio), determinar quantos 
pontos do array de pontos são internos à circunferência, imprimindo esse valor na tela; (0.7)

Liberar a memória alocada dinamicamente; (0.2)

OBS - um ponto é dito interno a uma circunferência se sua distância ao centro da mesma é menor que o raio. 
O cálculo da distância entre dois pontos é dada pela equação  (x1 - x2) 2+ (y1 - y2)2  . Use a biblioteca math.h

*/