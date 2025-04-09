#include <stdio.h>

int main (void) {

    typedef  struct {
        /* data */
        char tipo[25];
        float peso;
        int comprimento;
    } Peixe;

    /* Criando uma variável do tipo 'Peixe' */

    Peixe p1 = {"Tilápia", 0.7, 37};

    /* Criando um ponteiro para p1 */
    Peixe *ptr = &p1;
    

    return 0;

}