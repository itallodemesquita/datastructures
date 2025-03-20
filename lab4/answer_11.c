/* Questão 11 - Laboratório IV */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {

    setlocale(LC_ALL, "Portuguese"); /* Seta o código para o Português */

    FILE *file;
    int number;

    // Verifica se o arquivo existe
    file = fopen("interger.bin", "rb");

    if (file != NULL) {
        // Lê e printa o número armazenado no arquivo
        fread(&number, sizeof(int), 1, file);
        printf("Arquivo encontrado!\nO número armazenado no arquivo é: %d\n", number);
        fclose(file);

    } else {
        // Lê número do usuário
        printf("Digite um número inteiro: ");
        scanf("%d", &number);

        // Cria o arquivo e armazena o número
        file = fopen("interger.bin", "wb");
        if (file == NULL) {
            perror("Erro ao abrir o arquivo");
            return 1;
        }
        fwrite(&number, sizeof(int), 1, file);

        printf("Número armazenado com sucesso!\n");

        fclose(file);
    }

    return 0;
}

