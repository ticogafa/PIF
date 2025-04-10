#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    // Declara uma string com tamanho máximo de 100 caracteres
    char senha[100];
    
    // Lê entradas até o final do arquivo (EOF)
    while (fgets(senha, sizeof(senha), stdin)) {
        // Remove o '\n' final, se existir
        int tamanho = strlen(senha);
        if (tamanho > 0 && senha[tamanho-1] == '\n') {
            senha[tamanho-1] = '\0';  // Substitui '\n' por '\0' (fim de string)
            tamanho--;  // Atualiza o tamanho da string
        }

        // Variáveis para controlar os requisitos da senha
        int tem_maiuscula = 0;  // Indica se tem letra maiúscula
        int tem_minuscula = 0;  // Indica se tem letra minúscula
        int tem_digito = 0;     // Indica se tem número
        int invalida = 0;       // Indica se a senha é inválida

        // Verifica se o tamanho está dentro do intervalo permitido
        if (tamanho < 6 || tamanho > 32) {
            invalida = 1;
        }

        // Analisa cada caractere da senha
        for (int i = 0; i < tamanho && !invalida; i++) {
            char c = senha[i];
            
            // Verifica se é letra maiúscula
            if (isupper(c)) {
                tem_maiuscula = 1;
            } 
            // Verifica se é letra minúscula
            else if (islower(c)) {
                tem_minuscula = 1;
            } 
            // Verifica se é um dígito numérico
            else if (isdigit(c)) {
                tem_digito = 1;
            } 
            // Se não for letra nem número, a senha é inválida
            else {
                invalida = 1;
            }
        }

        // Verifica se todos os requisitos foram atendidos
        if (!invalida && tem_maiuscula && tem_minuscula && tem_digito) {
            printf("Senha valida.\n");
        } else {
            printf("Senha invalida.\n");
        }
    }
    return 0;
}
