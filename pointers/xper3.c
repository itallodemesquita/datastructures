/* Questão 8 - Lista I */

#include <stdio.h>

int main () {

    float x, *px = &x;

    printf("Digite um numero: ");
    scanf("%f", px);

    printf("A operacao x/3 eh igual a %.2f", (*px / 3));

    return 0;
}