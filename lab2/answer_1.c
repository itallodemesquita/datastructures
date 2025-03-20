/* Questão 1 - Laboratório II */

/* I. Definindo um registro peixe */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct peixe {
    char tipo[20];
    float peso;
    int comprimento;
};

/* Criando uma variável do tipo peixe */

int main () {

    struct peixe p1; // nomeando a variável p1 do tipo peixe

    // Atribuindo valores aos campos da variável p1
    strcpy(p1.tipo, "Tilapia");
    p1.peso = 0.5;
    p1.comprimento = 20;

    // Exibindo os valores dos campos da variável p1
    printf("Exibindo dados da variável p1: \n\n");
    printf("Tipo: %s\n", p1.tipo);
    printf("Peso: %.2f\n", p1.peso);
    printf("Comprimento: %d\n", p1.comprimento);

    /* Criando um ponteiro para p1 */
    struct peixe *ptr = &p1;

    // Exibindo os valores dos campos da variável p1 através do ponteiro ptr
    printf("\n\nExibindo dados através do ponteiro ptr: \n");
    printf("Tipo: %s\n", ptr->tipo);
    printf("Peso: %.2f\n", ptr->peso);
    printf("Comprimento: %d\n", ptr->comprimento);

    return 0;

}
