#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int is_number (const char *word) {
    for (int i = 0; word[i] != '\0'; i++) { /* Loop que percorre todos os caracteres da palavra até encontrar um caractere nulo */
        if (!isdigit(word[i])) /* Verifica se é número */
        return 0; /* Retorna 0 se o caractere não for número */
    }

    return 1; /* Retorna 1 se o caractere da palavra for um número */

}

int main (){

    FILE *fin = fopen("weather.txt", "r");
    FILE *fout = fopen("numbers.txt", "w");

    char word[50];

    while (fscanf(fin, "%s", word) != EOF) {

        if (is_number(word)) {
            fprintf (fout, "%s\n", word);
        }

    }
}