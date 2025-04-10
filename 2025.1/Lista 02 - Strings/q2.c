#include <stdio.h>
#include <string.h>

#define MAX_LANGUAGE_LENGTH 21  // 20 characters + 1 for null terminator

int main() {
    int n, k;
    char languages[100][MAX_LANGUAGE_LENGTH];
    
    scanf("%d", &n);
    
    for (int testCase = 0; testCase < n; testCase++) {
        scanf("%d", &k);
        
        for (int i = 0; i < k; i++) {
            scanf("%s", languages[i]);
        }
        
        int allSame = 1;
        for (int i = 1; i < k; i++) {
            if (strcmp(languages[0], languages[i]) != 0) {
                allSame = 0;
                break;
            }
        }
        
        if (allSame) {
            printf("%s\n", languages[0]);
        } else {
            printf("ingles\n");
        }
    }
    
    return 0;
}
