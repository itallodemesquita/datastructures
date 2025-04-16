/* Questão 6 - Lista I */

#include <stdio.h>

int main () {

    int x;
    int *px = &x;

    printf("Digite um numero inteiro: ");
    scanf("%d", px);

    printf("Valor de x = %d", *px);


    return 0;
}