
//1967 - A fronteira final

#include <stdio.h>

void lermatriz(int linhas, int colunas, int matriz[linhas][colunas]) {
  for(int i = 0; i < linhas; i++){
    for(int j = 0; j < colunas; j++){
      scanf("%d", &matriz[i][j]);
    }
  }
}

int main(){

  int G, A, M, C;
  scanf("%d %d %d %d", &G, &A, &M, &C);
  int GA[G][A], AM[A][M], MC[M][C];

  lermatriz(G, A, GA);
  lermatriz(A, M, AM);
  lermatriz(M, C, MC);

  int GM[G][M], GC[G][C];
  for(int g = 0; g < G; g++){
    for(int m = 0; m < M; m++){
      GM[g][m] = 0;
      for(int k = 0; k < A; k++){
        GM[g][m] += GA[g][k] * AM[k][m];
      }
    }
  }
  for(int g1 = 0; g1 < G; g1++){
    for(int c = 0; c < C; c++){
      GC[g1][c] = 0;
      for(int k1 = 0; k1 < M; k1++){
        GC[g1][c] += GM[g1][k1] * MC[k1][c];
      }
    }
  }
  for(int r = 0; r < G; r++){
    printf("\n");
    for(int e = 0; e < C; e++){
      printf(" %d", GC[r][e]);
    }
  }

  return 0;
}