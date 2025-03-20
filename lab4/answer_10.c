#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    float peso;
    int idade;
} Peixe;

int main() {
    FILE *arquivoTexto, *arquivoBinario;
    Peixe peixe;
    int count = 0;

    // Abrir o arquivo texto para leitura
    arquivoTexto = fopen("peixes.txt", "r");
    if (arquivoTexto == NULL) {
        printf("Erro ao abrir o arquivo texto.\n");
        return 1;
    }

    // Abrir o arquivo binário para escrita
    arquivoBinario = fopen("peixes.bin", "wb");
    if (arquivoBinario == NULL) {
        printf("Erro ao abrir o arquivo binário.\n");
        fclose(arquivoTexto);
        return 1;
    }

    // Ler os dados do arquivo texto e escrever no arquivo binário
    while (fscanf(arquivoTexto, "%s %f %d", peixe.nome, &peixe.peso, &peixe.idade) != EOF) {
        fwrite(&peixe, sizeof(Peixe), 1, arquivoBinario);
        count++;
    }

    fclose(arquivoTexto);
    fclose(arquivoBinario);

    // Abrir o arquivo binário para leitura
    arquivoBinario = fopen("peixes.bin", "rb");
    if (arquivoBinario == NULL) {
        printf("Erro ao abrir o arquivo binário.\n");
        return 1;
    }

    // Ler e exibir os dados do arquivo binário
    printf("Dados dos peixes:\n");
    while (fread(&peixe, sizeof(Peixe), 1, arquivoBinario) == 1) {
        printf("Nome: %s, Peso: %.2f, Idade: %d\n", peixe.nome, peixe.peso, peixe.idade);
    }

    fclose(arquivoBinario);

    return 0;
}