#include <stdio.h>

int main(void){
	int linha, coluna;
	scanf("%d %d", &linha, &coluna);
	int a[linha][coluna];
	for(int i = 0; i<linha; i++){
    for(int j = 0; j<coluna;j++){
      scanf("%d", &a[i][j]);
    }
	}
  for(int i = 0; i<linha; i++){
    printf("\n");
    for(int j = 0; j<coluna;j++){
      printf("[%d]", a[i][j]);
    }
  }
	return 0;
}