#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){

  int n=0, size;
  char **nomes, tmp[100];
  scanf("%d", &n);
  nomes = (char**)malloc(n*sizeof(char*));

  for(int i = 0; i<n;i++){
    scanf("%s", tmp);
    size = strlen(tmp);
    nomes[i] = (char*)malloc((size + 1)*sizeof(char));
    strcpy(nomes[i], tmp);
  }

  for(int i = 0; i<n; i++){
    printf("%s\n", nomes[i]);
  }

  for(int i = 0; i<n; i++){
    free(nomes[i]);
  }
  free(nomes);
  
  return 0;
}