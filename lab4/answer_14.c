#include <stdio.h>
#include <stdlib.h>

int main() {

    int largura, altura;
    int **image;
    char escolha;
    FILE *arquivo = fopen("imagem.bin", "wb");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    while (1) { /* Loop principal */
        printf("Escolha uma opção:\n");
        printf("1. Guardar nova imagem\n");
        printf("2. Exibir imagem armazenada\n");
        printf("3. Sair\n");
        printf("Opção: ");
        scanf(" %c", &escolha);

        if (escolha == '1') {
            printf("Digite a largura da imagem: ");
            scanf("%d", &largura);
            printf("Digite a altura da imagem: ");
            scanf("%d", &altura);

            /* Aloca memória para a imagem */
            image = (int **)malloc(altura * sizeof(int *));
            for (int i = 0; i < altura; i++) {
                image[i] = (int *)malloc(largura * sizeof(int));
            }

            /* Lê os valores da imagem */
            printf("Digite os valores da imagem (cada valor representa a cor de um bloco):\n");
            for (int i = 0; i < altura; i++) {
                for (int j = 0; j < largura; j++) {
                    scanf("%d", &image[i][j]);
                }
            }


            /* Escreve a imagem no arquivo */
            fseek(arquivo, 0, SEEK_SET);
            fwrite(&largura, sizeof(int), 1, arquivo);
            fwrite(&altura, sizeof(int), 1, arquivo);
            for (int i = 0; i < altura; i++) {
                fwrite(image[i], sizeof(int), largura, arquivo);
            }

            printf("Imagem armazenada com sucesso!\n");

            for (int i = 0; i < altura; i++) {
                free(image[i]);
            }
            free(image);

            /* Exibe a imagem armazenada */
        } else if (escolha == '2') {
            /* Lê a imagem do arquivo */
            fseek(arquivo, 0, SEEK_SET);
            fread(&largura, sizeof(int), 1, arquivo);
            fread(&altura, sizeof(int), 1, arquivo);


            /* Aloca memória para a imagem */
            image = (int **)malloc(altura * sizeof(int *));
            for (int i = 0; i < altura; i++) {
                image[i] = (int *)malloc(largura * sizeof(int));
            }

            /* Lê os valores da imagem */
            for (int i = 0; i < altura; i++) {
                fread(image[i], sizeof(int), largura, arquivo);
            }

            printf("Imagem armazenada:\n");
            for (int i = 0; i < altura; i++) {
                for (int j = 0; j < largura; j++) {
                    printf("%03d ", image[i][j]);
                }
                printf("\n");
            }

            for (int i = 0; i < altura; i++) {
                free(image[i]);
            }
            free(image);

        } else if (escolha == '3') {
            break;

        } else {
            printf("Opção inválida. Tente novamente.\n");
        }
    }

    fclose(arquivo);
    return 0;

}