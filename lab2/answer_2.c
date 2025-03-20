/* Questão 2 - Laboratório II */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct peixe {
    char tipo[20];
    float peso;
    int comprimento;
};

/* Função que recebe um peixe como parâmetro, que exibe os campos de uma struct */
void exibir_peixe(struct peixe p) {
    printf("Exibindo dados da variável p: \n\n");
    printf("Tipo: %s\n", p.tipo);
    printf("Peso: %.2f\n", p.peso);
    printf("Comprimento: %d\n", p.comprimento);
}

/* Função que recebe um ponteiro como parâmetro, que exibe os campos de uma struct */
void exibir_peixe_ptr(struct peixe *ptr) {
    printf("\n\nExibindo dados através do ponteiro ptr: \n");
    printf("Tipo: %s\n", ptr->tipo);
    printf("Peso: %.2f\n", ptr->peso);
    printf("Comprimento: %d\n", ptr->comprimento);
}

int main () {
    
    struct peixe p1; // nomeando a variável p1 do tipo peixe

    // Atribuindo valores aos campos da variável p1
    strcpy(p1.tipo, "Tilapia");
    p1.peso = 0.5;
    p1.comprimento = 20;

    // Exibindo os valores dos campos da variável p1
    exibir_peixe(p1);

    /* Criando um ponteiro para p1 */
    struct peixe *ptr = &p1;

    // Exibindo os valores dos campos da variável p1 através do ponteiro ptr
    exibir_peixe_ptr(ptr);

    return 0;
}