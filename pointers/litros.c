#include <stdio.h>

int main () {
    double litros = 3.4;
    double *ptr = &litros;

    printf("O valor de litros é %f", *ptr);


    return 0;
}
