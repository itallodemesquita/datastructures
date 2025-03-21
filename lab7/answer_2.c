/* Questão 2 - Laboratório VII */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
} DoublyLinkedList;

DoublyLinkedList* create_list() {
    DoublyLinkedList* list = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

// Função para inserir um nó no início da lista
void inserir_no_inicio(DoublyLinkedList* list, int valor) { 
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = valor;
    new_node->prev = NULL;
    new_node->next = list->head;
    if (list->head != NULL) {
        list->head->prev = new_node;
    } else {
        list->tail = new_node;
    }
    list->head = new_node;
}
// Função para inserir um nó no final da lista
void inserir_no_fim(DoublyLinkedList* list, int valor) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = valor;
    new_node->next = NULL;
    new_node->prev = list->tail;
    if (list->tail != NULL) {
        list->tail->next = new_node;
    } else {
        list->head = new_node;
    }
    list->tail = new_node;
}

void remover(DoublyLinkedList* list, int valor) {
    Node* current = list->head;
    while (current != NULL && current->data != valor) {
        current = current->next;
    }
    if (current == NULL) {
        return;
    }
    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        list->head = current->next;
    }
    if (current->next != NULL) {
        current->next->prev = current->prev;
    } else {
        list->tail = current->prev;
    }
    free(current);
}

int buscar(DoublyLinkedList* list, int valor) {
    Node* current = list->head;
    while (current != NULL) {
        if (current->data == valor) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void exibir(DoublyLinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

