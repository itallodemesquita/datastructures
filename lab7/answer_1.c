/* Questão 1 - Laboratório VII */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura do nó
typedef struct Node {
    int valor;
    struct Node* proximo;
} Node;

// Função para criar um novo nó
Node* criar_no(int valor) {
    Node* novo_no = (Node*)malloc(sizeof(Node));
    if (novo_no == NULL) {
        printf("Erro de alocação de memória\n");
        exit(1);
    }
    
    novo_no->valor = valor;
    novo_no->proximo = NULL;
    return novo_no;
}

// Função para inserir um nó no início da lista
void inserir_no_inicio(Node** cabeca, int valor) {
    Node* novo_no = criar_no(valor);
    novo_no->proximo = *cabeca;
    *cabeca = novo_no;
}

// Função para inserir um nó no final da lista
void inserir_no_fim(Node** cabeca, int valor) {
    Node* novo_no = criar_no(valor);
    if (*cabeca == NULL) {
        *cabeca = novo_no;
    } else {
        Node* temp = *cabeca;
        while (temp->proximo != NULL) {
            temp = temp->proximo;
        }
        temp->proximo = novo_no;
    }
}

// Função para remover um nó específico
void remover(Node** cabeca, int valor) {
    Node* temp = *cabeca;
    Node* anterior = NULL;

    // Se o nó a ser removido é a cabeça da lista
    if (temp != NULL && temp->valor == valor) {
        *cabeca = temp->proximo;
        free(temp);
        return;
    }

    // Procurar o nó a ser removido
    while (temp != NULL && temp->valor != valor) {
        anterior = temp;
        temp = temp->proximo;
    }

    // Se o valor não foi encontrado na lista
    if (temp == NULL) return;

    // Desvincular o nó da lista
    anterior->proximo = temp->proximo;
    free(temp);
}

// Função para buscar um valor na lista
int buscar(Node* cabeca, int valor) {
    Node* temp = cabeca;
    while (temp != NULL) {
        if (temp->valor == valor) {
            return 1; // Valor encontrado
        }
        temp = temp->proximo;
    }
    return 0; // Valor não encontrado
}

// Função para exibir todos os elementos da lista
void exibir(Node* cabeca) {
    Node* temp = cabeca;
    while (temp != NULL) {
        printf("%d -> ", temp->valor);
        temp = temp->proximo;
    }
    printf("NULL\n");
}

// Função principal para testar a lista encadeada
int main() {
    Node* cabeca = NULL;

    inserir_no_inicio(&cabeca, 10);
    inserir_no_inicio(&cabeca, 20);
    inserir_no_fim(&cabeca, 30);
    inserir_no_fim(&cabeca, 40);

    printf("Lista após inserções:\n");
    exibir(cabeca);

    remover(&cabeca, 20);
    printf("Lista após remover 20:\n");
    exibir(cabeca);

    int encontrado = buscar(cabeca, 30);
    printf("Buscar 30: %s\n", encontrado ? "Encontrado" : "Não encontrado");

    return 0;
}

/*

// Função para criar um novo nó em uma lista circular
Node* criar_no_circular(int valor) {
    Node* novo_no = (Node*)malloc(sizeof(Node));
    novo_no->valor = valor;
    novo_no->proximo = novo_no; // Aponta para si mesmo
    return novo_no;
}

// Função para inserir um nó no início da lista circular
void inserir_no_inicio_circular(Node** cabeca, int valor) {
    Node* novo_no = criar_no_circular(valor);
    if (*cabeca == NULL) {
        *cabeca = novo_no;
    } else {
        Node* temp = *cabeca;
        while (temp->proximo != *cabeca) {
            temp = temp->proximo;
        }
        novo_no->proximo = *cabeca;
        temp->proximo = novo_no;
        *cabeca = novo_no;
    }
}

// Função para inserir um nó no final da lista circular
void inserir_no_fim_circular(Node** cabeca, int valor) {
    Node* novo_no = criar_no_circular(valor);
    if (*cabeca == NULL) {
        *cabeca = novo_no;
    } else {
        Node* temp = *cabeca;
        while (temp->proximo != *cabeca) {
            temp = temp->proximo;
        }
        temp->proximo = novo_no;
        novo_no->proximo = *cabeca;
    }
}

// Função para remover um nó específico da lista circular
void remover_circular(Node** cabeca, int valor) {
    if (*cabeca == NULL) return;

    Node* temp = *cabeca;
    Node* anterior = NULL;

    // Se o nó a ser removido é a cabeça da lista
    if (temp->valor == valor) {
        if (temp->proximo == *cabeca) {
            free(temp);
            *cabeca = NULL;
        } else {
            while (temp->proximo != *cabeca) {
                temp = temp->proximo;
            }
            Node* to_remove = *cabeca;
            temp->proximo = (*cabeca)->proximo;
            *cabeca = (*cabeca)->proximo;
            free(to_remove);
        }
        return;
    }

    // Procurar o nó a ser removido
    anterior = *cabeca;
    temp = (*cabeca)->proximo;
    while (temp != *cabeca && temp->valor != valor) {
        anterior = temp;
        temp = temp->proximo;
    }

    // Se o valor não foi encontrado na lista
    if (temp == *cabeca) return;

    // Desvincular o nó da lista
    anterior->proximo = temp->proximo;
    free(temp);
}

// Função para buscar um valor na lista circular
int buscar_circular(Node* cabeca, int valor) {
    if (cabeca == NULL) return 0;

    Node* temp = cabeca;
    do {
        if (temp->valor == valor) {
            return 1; // Valor encontrado
        }
        temp = temp->proximo;
    } while (temp != cabeca);

    return 0; // Valor não encontrado
}

// Função para exibir todos os elementos da lista circular
void exibir_circular(Node* cabeca) {
    if (cabeca == NULL) {
        printf("NULL\n");
        return;
    }

    Node* temp = cabeca;
    do {
        printf("%d -> ", temp->valor);
        temp = temp->proximo;
    } while (temp != cabeca);
    printf("(cabeça)\n");
}

// Função principal para testar a lista circular
int main() {
    Node* cabeca = NULL;

    inserir_no_inicio_circular(&cabeca, 10);
    inserir_no_inicio_circular(&cabeca, 20);
    inserir_no_fim_circular(&cabeca, 30);
    inserir_no_fim_circular(&cabeca, 40);

    printf("Lista após inserções:\n");
    exibir_circular(cabeca);

    remover_circular(&cabeca, 20);
    printf("Lista após remover 20:\n");
    exibir_circular(cabeca);

    int encontrado = buscar_circular(cabeca, 30);
    printf("Buscar 30: %s\n", encontrado ? "Encontrado" : "Não encontrado");

    return 0;
}

*/