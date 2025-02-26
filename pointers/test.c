#include <stdio.h>
#include <locale.h>

int main () {

    setlocale(LC_ALL, "Portuguese"); /* Seta o código para o Português */

    char ch = 'G';
    char *ptr = &ch;

    printf("Endereço de 'ch': %p\n", ptr);
    printf("Valor de 'ch': %c\n", *ptr);

    return 0;

}