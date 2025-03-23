#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union Senha {
    char alfanumerica[50];
    int numerica;
};

void gravaSenha(union Senha senha, int tipo) {
    FILE *file = fopen("senha.bin", "wb");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }
    fwrite(&tipo, sizeof(int), 1, file);
    if (tipo == 1) {
        fwrite(senha.alfanumerica, sizeof(senha.alfanumerica), 1, file);
    } else if (tipo == 2) {
        fwrite(&senha.numerica, sizeof(int), 1, file);
    }
    fclose(file);
}

void exibeSenha() {
    FILE *file = fopen("senha.bin", "rb");
    if (file == NULL) {
        printf("Arquivo não encontrado.\n");
        return;
    }
    int tipo;
    fread(&tipo, sizeof(int), 1, file);
    union Senha senha;
    if (tipo == 1) {
        fread(senha.alfanumerica, sizeof(senha.alfanumerica), 1, file);
        printf("Senha Alfanumérica: %s\n", senha.alfanumerica);
    } else if (tipo == 2) {
        fread(&senha.numerica, sizeof(int), 1, file);
        printf("Senha Numérica: %d\n", senha.numerica);
    }
    fclose(file);
}

int main() {
    char opcao;
    union Senha senha;
    int tipo;

    do {
        printf("\nEscolha uma opção:\n");
        printf("[G]ravar nova senha\n");
        printf("[E]xibir senha\n");
        printf("[S]air\n");
        scanf(" %c", &opcao);
        getchar(); // Lê \n do buffer

        switch (opcao) {
            case 'G':
            case 'g':
                printf("Escolha o tipo de senha:\n");
                printf("[1] Alfanumérica\n");
                printf("[2] Numérica\n");
                scanf("%d", &tipo);
                getchar(); // Lê \n do buffer
                if (tipo == 1) {
                    printf("Digite a senha alfanumérica: ");
                    fgets(senha.alfanumerica, 50, stdin);
                    senha.alfanumerica[strcspn(senha.alfanumerica, "\n")] = '\0'; // Remove \n
                } else if (tipo == 2) {
                    printf("Digite a senha numérica: ");
                    scanf("%d", &senha.numerica);
                } else {
                    printf("Tipo inválido.\n");
                    break;
                }
                gravaSenha(senha, tipo);
                break;
            case 'E':
            case 'e':
                exibeSenha();
                break;
            case 'S':
            case 's':
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 'S' && opcao != 's');

    return 0;
}