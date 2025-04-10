//QUESTÃO 02 (STRINGS - Buscador textual  - 1.5 pontos): Faça uma função capaz de procurar uma palavra dentro de um texto. Sua função deve:
//A)Receber dois parâmetros: um texto de no máximo 1000 caracteres e uma palavra de no máximo 20 caracteres; (0.25 pontos)
//B)Percorrer o texto e  identificar se a palavra esta contida no mesmo ou não; (1.0 pontos)
//C)Se a palavra aparece ao menos uma vez, sua função deve retornar 1. Caso contraŕio, retorne 0; (0.25 pontos)
//
#include <stdio.h>

int buscar_palavra(const char *texto, const char *palavra) {
    int texto_len = strlen(texto);
    int palavra_len = strlen(palavra);
    
    for (int i = 0; i <= texto_len - palavra_len; i++) {
        int j;
        for (j = 0; j < palavra_len; j++) {
            if (texto[i + j] != palavra[j]) {
                break;
            }
        }
        if (j == palavra_len) {
            return 1;
        }
    }
    return 0;
}