#include <stdio.h>

int main(void){
	int cont;
	// Ler o número de elementos a serem armazenados no array
	scanf("%d", &cont);
	
	// Declarar um array de tamanho 'cont'
	int a[cont];
	
	// Ler 'cont' número de elementos no array
	for(int i = 0; i < cont; i++){
		scanf("%d", &a[i]);
	}
	
	// Imprimir os elementos do array com seus índices
	for(int j = 0; j < cont; j++){
		printf("%d: [%d]\n", j, a[j]);
	}
	
	return 0;
}