/* Questão 3 - Laboratório II */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct players {
    char name[20];
    char team[20];
    int goals;
    int assists;
};


int main () {

    struct players p1; // nomeando a variável p1 do tipo players

    // Atribuindo valores aos campos da variável p1
    strcpy(p1.name, "Memphis Depay");
    strcpy(p1.team, "Corinthians");
    p1.goals = 9;
    p1.assists = 11;

    // Exibindo os valores dos campos da variável p1
    printf("Exibindo dados da variável p1: \n\n");
    printf("Nome: %s\n", p1.name);
    printf("Time: %s\n", p1.team);
    printf("Gols: %d\n", p1.goals);
    printf("Assistências: %d\n", p1.assists);

    // Acessando um ponteiro com um endereço inválido
    struct players *ptrInvalid;

    // Exibindo os valores dos campos da variável p1 através do ponteiro ptrInvalid
    printf("\n\nExibindo dados através do ponteiro ptrInvalid: \n");
    printf("Nome: %s\n", ptrInvalid->name);
    printf("Time: %s\n", ptrInvalid->team);
    printf("Gols: %d\n", ptrInvalid->goals);
    printf("Assistências: %d\n", ptrInvalid->assists);

    return 0;
}

// O que acontece quando tentamos acessar um ponteiro sem endereço?

// Acessar um ponteiro sem endereço é um comportamento indefinido, pois o ponteiro não aponta para um endereço válido.
// O programa pode exibir valores aleatórios, travar ou até mesmo gerar um erro de segmentação.
// No caso do código acima, o programa exibe valores aleatórios para os campos da struct players, pois o ponteiro ptrInvalid não aponta para um endereço válido.
// Isso ocorre porque o ponteiro ptrInvalid não foi inicializado com um endereço válido, ou seja, ele não aponta para nenhuma variável do tipo struct players.