#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main () {

    setlocale(LC_ALL, "Portuguese");

    int number;
    int i = 0;
    int j = 0;
    FILE *arquivo = fopen("vet.dat", "rb");
    int vet[100];

    do {

        printf("Digite um número inteiro. Para encerrar, digite 0: ");
        scanf("%d", &number);
        vet[j] = number;
        j++;
        fwrite(&number, sizeof(int), 1, arquivo);
        i++;

        if (number == 0) {
            vet[j] = '\0';
            break;
        }
    }
    while (number != 0);

    fclose(arquivo);

    printf("Números armazenados em vet.dat: ");
    for (int k = 0; k < j - 1; k++) {
        printf("%d ", vet[k]);
    }
    printf("\n\n%d números foram armazenados em vet.dat.\n", i - 1);

    return 0;
    
}