#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main () {

    setlocale(LC_ALL, "Portuguese");

    char escolha;
    char mensagem[80];
    int textColor;
    int backgroundColor;
    FILE *arquivo = fopen("mensagens.bin", "wb");

    printf("Questão 13 - Laboratório IV\n\n");

    

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    while (1) {
        printf("Escolha uma opção:\n");
        printf("1. Guardar nova frase\n");
        printf("2. Exibir frase armazenada\n");
        printf("3. Sair\n");
        printf("Opção: ");
        scanf(" %c", &escolha);

        if (escolha == '1') {
            printf("Digite uma mensagem (máximo 80 caracteres): ");
            getchar(); // Limpar o buffer do teclado
            fgets(mensagem, sizeof(mensagem), stdin);

            printf("Digite o código da cor do texto (000-255): ");
            scanf("%d", &textColor);

            printf("Digite o código da cor do fundo (000-255): ");
            scanf("%d", &backgroundColor);

            fseek(arquivo, 0, SEEK_SET);
            fwrite(mensagem, sizeof(char), sizeof(mensagem), arquivo);
            fwrite(&textColor, sizeof(int), 1, arquivo);
            fwrite(&backgroundColor, sizeof(int), 1, arquivo);

            printf("Mensagem armazenada com sucesso!\n");

        } else if (escolha == '2') {
            fseek(arquivo, 0, SEEK_SET);
            fread(mensagem, sizeof(char), sizeof(mensagem), arquivo);
            fread(&textColor, sizeof(int), 1, arquivo);
            fread(&backgroundColor, sizeof(int), 1, arquivo);

            printf("Mensagem armazenada: %s\n", mensagem);
            printf("Cor do texto: %d\n", textColor);
            printf("Cor do fundo: %d\n", backgroundColor);

        } else if (escolha == '3') {
            break;

        } else {
            printf("Opção inválida. Tente novamente.\n");
        }
    }

    fclose(arquivo);
    return 0;

}