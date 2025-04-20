    /*
    * Problema: Frequência de Caracteres
    * 
    * Descrição: Este programa lê várias linhas de texto e, para cada linha,
    * conta a frequência de cada caractere. Em seguida, imprime o valor ASCII
    * e a frequência de cada caractere, ordenados por frequência (crescente) e,
    * em caso de empate, por valor ASCII (decrescente).
    * 
    * Entrada: Várias linhas de texto.
    * Saída: Para cada linha, o código ASCII e a frequência de cada caractere,
    *        com uma linha em branco entre os casos de teste.
    */

    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>

    #define MAX_LENGTH 1001  // Tamanho máximo da linha + terminador nulo

    // Estrutura para armazenar informações de cada caractere
    typedef struct {
        int ascii;     // Valor ASCII do caractere
        int frequency; // Frequência do caractere no texto
    } CharInfo;

    // Função de comparação para ordenação dos caracteres
    int comparar(const void *a, const void *b) {
        // Converte os ponteiros void para ponteiros CharInfo
        CharInfo *charA = (CharInfo *)a;
        CharInfo *charB = (CharInfo *)b;
        
        // Se as frequências são iguais, ordena pelo valor ASCII (decrescente)
        if (charA->frequency == charB->frequency) {
            return charB->ascii - charA->ascii;
        }
        
        // Caso contrário, ordena pela frequência (crescente)
        return charA->frequency - charB->frequency;
    }

    int main() {
        char line[MAX_LENGTH];  // Buffer para armazenar cada linha de texto
        int firstLine = 1;  // Flag para verificar se é a primeira linha
        
        // Lê linhas até o fim da entrada (EOF)
        while (fgets(line, MAX_LENGTH, stdin) != NULL) {
            // Adiciona uma linha em branco entre casos de teste (não na primeira linha)
            if (!firstLine) {
                printf("\n");
            } else {
                firstLine = 0;
            }
            
            // Remove o caractere de nova linha, se existir
            int len = strlen(line);
            if (len > 0 && line[len - 1] == '\n') {
                line[len - 1] = '\0';  // Substitui o '\n' pelo terminador nulo
                len--;                 // Atualiza o comprimento da string
            }
            
            // Inicializa o array de frequências com zeros
            int freq[256] = {0};  // Índices de 0 a 255 para todos os caracteres ASCII
            
            // Conta a frequência de cada caractere na linha
            for (int i = 0; i < len; i++) {
                freq[(unsigned char)line[i]]++;  // Incrementa a contagem do caractere atual
            }
            
            // Cria uma lista apenas com os caracteres que aparecem na linha
            CharInfo charInfo[256];
            int uniqueChars = 0;  // Contador de caracteres únicos
            
            for (int i = 0; i < 256; i++) {
                if (freq[i] > 0) {  // Se o caractere aparece pelo menos uma vez
                    charInfo[uniqueChars].ascii = i;
                    charInfo[uniqueChars].frequency = freq[i];
                    uniqueChars++;
                }
            }
            
            // Ordena os caracteres usando a função de comparação definida
            qsort(charInfo, uniqueChars, sizeof(CharInfo), comparar);       
            
            // Imprime os resultados no formato: ASCII frequência
            for (int i = 0; i < uniqueChars; i++) {
                printf("%d %d\n", charInfo[i].ascii, charInfo[i].frequency);
            }
        }
        printf("\n");
        return 0;  // Indica que o programa terminou com sucesso
    }
