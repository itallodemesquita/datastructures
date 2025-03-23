#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura Soldado
struct Soldado {
    char nome[50];
    int eliminacoes;
    int mortes;
    float taxa;
    int partidas;
};

// Função para exibir os dados de um soldado
void exibeSoldado(struct Soldado s) {
    printf("Nome: %s\n", s.nome);
    printf("Eliminações: %d\n", s.eliminacoes);
    printf("Mortes: %d\n", s.mortes);
    printf("Taxa de Eliminações/Mortes: %.2f\n", s.taxa);
    printf("Número de Partidas: %d\n", s.partidas);
}

// Função para atualizar a taxa de eliminações/mortes de um soldado
void atualizaTaxa(struct Soldado *s) {
    if (s->mortes != 0) {
        s->taxa = (float)s->eliminacoes / s->mortes;
    } else {
        s->taxa = (float)s->eliminacoes;
    }
}

int main() {
    struct Soldado soldado;
    FILE *file = fopen("soldado.bin", "rb"); // Abre o arquivo binário para leitura

    if (file == NULL) { // Se o arquivo não existir, cria um novo soldado
        printf("Arquivo não encontrado. Criando um novo soldado.\n");
        printf("Digite o nome do soldado: ");
        fgets(soldado.nome, 50, stdin);
        soldado.nome[strcspn(soldado.nome, "\n")] = '\0';
        printf("Digite o número de eliminações: ");
        scanf("%d", &soldado.eliminacoes);
        printf("Digite o número de mortes: ");
        scanf("%d", &soldado.mortes);
        printf("Digite o número de partidas jogadas: ");
        scanf("%d", &soldado.partidas);
        atualizaTaxa(&soldado);
    } else {
        fread(&soldado, sizeof(struct Soldado), 1, file);
        fclose(file);
    }

    char opcao;
    do {
        printf("\nEscolha uma opção:\n");
        printf("[N]ovo soldado\n");
        printf("[A]tualiza soldado\n");
        printf("[E]xibe soldado\n");
        printf("[s]air\n");
        scanf(" %c", &opcao);
        getchar();

        switch (opcao) { // Menu de opções
            case 'N':
            case 'n':
                printf("Digite o nome do soldado: ");
                fgets(soldado.nome, 50, stdin);
                soldado.nome[strcspn(soldado.nome, "\n")] = '\0';
                printf("Digite o número de eliminações: ");
                scanf("%d", &soldado.eliminacoes);
                printf("Digite o número de mortes: ");
                scanf("%d", &soldado.mortes);
                printf("Digite o número de partidas jogadas: ");
                scanf("%d", &soldado.partidas);
                atualizaTaxa(&soldado);
                break;
            case 'A':
            case 'a':
                printf("Digite o número de eliminações na última partida: ");
                int novasEliminacoes;
                scanf("%d", &novasEliminacoes);
                printf("Digite o número de mortes na última partida: ");
                int novasMortes;
                scanf("%d", &novasMortes);
                soldado.eliminacoes += novasEliminacoes;
                soldado.mortes += novasMortes;
                soldado.partidas += 1;
                atualizaTaxa(&soldado);
                break;
            case 'E':
            case 'e':
                exibeSoldado(soldado);
                break;
            case 's':
                file = fopen("soldado.bin", "wb");
                fwrite(&soldado, sizeof(struct Soldado), 1, file);
                fclose(file);
                printf("Soldado salvo no arquivo.\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 's');

    return 0;
}