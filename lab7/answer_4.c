/* Questão 4 - Laboratório VII */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define um registro para representar um título
typedef struct {
    char nome[100];
    int ano_lancamento;
    char categoria[50];
} Title;

// Define um registro para representar uma lista de títulos
typedef struct {
    Title *titles;
    int size;
    int capacity;
} TitleList;

// Função para inicializar a lista de títulos
void iniciarLista(TitleList *list, int capacity) {
    list->titles = (Title *)malloc(capacity * sizeof(Title));
    list->size = 0;
    list->capacity = capacity;
}

// Função para adicionar um título à lista
void addTitulo(TitleList *list, char *nome, int ano_lancamento, char *categoria) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->titles = (Title *)realloc(list->titles, list->capacity * sizeof(Title));
    }
    strcpy(list->titles[list->size].nome, nome);
    list->titles[list->size].ano_lancamento = ano_lancamento;
    strcpy(list->titles[list->size].categoria, categoria);
    list->size++;
}

// Pesquisa por categoria
void pesquisaPorCategoria(TitleList *list, char *categoria) {
    int encontrado = 0;
    printf("Títulos na categoria: '%s':\n", categoria);
    for (int i = 0; i < list->size; i++) {
        if (strcmp(list->titles[i].categoria, categoria) == 0) {
            printf("%s (%d)\n", list->titles[i].nome, list->titles[i].ano_lancamento);
            encontrado = 1;
        }
    }
    if (!encontrado) {
        printf("Nenhum título encontrado nesta categoria.\n");
    }
}

// Função de comparação para ordenar por ano de lançamento
int ordenarAno(const void *a, const void *b) {
    Title *titleA = (Title *)a;
    Title *titleB = (Title *)b;
    return titleA->ano_lancamento - titleB->ano_lancamento;
}

// Função para listar os títulos por ano de lançamento
void listarPorAno(TitleList *list) {
    qsort(list->titles, list->size, sizeof(Title), ordenarAno);
    printf("\n\nOrdenar pelo ano:\n");
    for (int i = 0; i < list->size; i++) {
        printf("%s (%d) - %s\n", list->titles[i].nome, list->titles[i].ano_lancamento, list->titles[i].categoria);
    }
}

// Função para liberar a memória alocada para a lista de títulos
void liberarTitulos(TitleList *list) {
    free(list->titles);
}

int main() {
    TitleList list;
    iniciarLista(&list, 10);

    addTitulo(&list, "The Matrix", 1999, "Sci-Fi");
    addTitulo(&list, "Breaking Bad", 2008, "Drama");
    addTitulo(&list, "The Sopranos", 1999, "Drama");
    addTitulo(&list, "Friends", 1994, "Comedy");
    addTitulo(&list, "The Godfather", 1972, "Crime");
    addTitulo(&list, "The Dark Knight", 2008, "Action");
    addTitulo(&list, "The Shawshank Redemption", 1994, "Drama");
    addTitulo(&list, "The Godfather: Part II", 1974, "Crime");
    addTitulo(&list, "The Lord of the Rings: The Return of the King", 2003, "Fantasy");
    addTitulo(&list, "Pulp Fiction", 1994, "Crime");

    pesquisaPorCategoria(&list, "Drama");

    listarPorAno(&list);


    liberarTitulos(&list);

    return 0;
}