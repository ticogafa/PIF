#include <stdio.h>

int main(void){
	int cont;
	scanf("%d", &cont);
	int a[cont];
	for(int i = 0; i<cont; i++){
	    scanf("%d", &a[i]);
	}
	for(int j = 0; j<cont; j++){
	    printf("%d: [%d]\n", j, a[j]);
	}
	return 0;
}