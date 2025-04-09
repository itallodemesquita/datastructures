/* Questão 2 */

#include <stdio.h>
#include <string.h>

struct Peixe {
    
    char tipo[25];
    float peso;
    int comprimento;
};

/* Exibe 'Peixe', tendo a variável como parâmetro */
void printFish (struct Peixe p) {

    printf("Peixe: \n\n");
    printf("Tipo: %s\n", p.tipo);
    printf("Peso: %.2f\n", p.peso);
    printf("Tamanho: %d\n", p.comprimento);

}

/* Exibe 'Peixe', tendo um ponteiro como parâmetro*/
void printFishPtr (struct Peixe *ptr) {

    printf("Peixe:\n\n");
    printf("Tipo: %s\n", ptr->tipo);
    printf("Peso: %.2f\n", ptr->peso);
    printf("Tamanho: %d\n", ptr->comprimento);

}

int main (void) {

    struct Peixe p1 = {"Bagre", 1.2, 55};
    struct Peixe *ptr = &p1;

    printf("\n\n");
    printFish(p1);
    printf("\n\n");
    printFishPtr(ptr);

}