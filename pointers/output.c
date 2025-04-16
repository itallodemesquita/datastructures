/* Questão 5 - Lista I */

#include <stdio.h>

int main () {

    int x = 68, y;
    int *p;
    p = &x;
    y = *p + 200;

    printf("x = %d, y = %d, ponteiro = %d", x, y, *p);

    return 0;
}