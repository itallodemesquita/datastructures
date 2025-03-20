/* Questão 9 - Laboratório 4 */

#include <stdio.h>
#include <stdlib.h>

struct peixe {
    char nome[50];
    float peso;
    float tamanho;
};

void cadastrar_peixe() {
    struct peixe p;
    FILE *file;

    // Abrir o arquivo binário para leitura e escrita (append)
    file = fopen("peixes.bin", "ab+");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    // Ler e exibir os peixes cadastrados
    printf("Peixes cadastrados:\n");
    rewind(file);
    while (fread(&p, sizeof(struct peixe), 1, file)) {
        printf("Nome: %s, Peso: %.2f, Tamanho: %.2f\n", p.nome, p.peso, p.tamanho);
    }

    // Solicitar dados do novo peixe
    printf("\nDigite o nome do peixe: ");
    scanf("%s", p.nome);
    printf("Digite o peso do peixe: ");
    scanf("%f", &p.peso);
    printf("Digite o tamanho do peixe: ");
    scanf("%f", &p.tamanho);

    // Escrever o novo peixe no arquivo
    fwrite(&p, sizeof(struct peixe), 1, file);

    // Fechar o arquivo
    fclose(file);
}

int main() {
    cadastrar_peixe();
    return 0;
}