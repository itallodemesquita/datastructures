#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUNOS 100
#define MAX_NOME 50

typedef struct {
    char nome[MAX_NOME];
    char turno;
    int serie;
} Aluno;

void exibeAlunosPorTurnoESerie(Aluno alunos[], int n, char turno, int serie) {
    printf("%s %da Série\n", (turno == 'M') ? "Matutino" : "Vespertino", serie);
    for (int i = 0; i < n; i++) {
        if (alunos[i].turno == turno && alunos[i].serie == serie) {
            printf("%s %c%d\n", alunos[i].nome, alunos[i].turno, alunos[i].serie);
        }
    }
}

int main() {
    FILE *file = fopen("alunos.txt", "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    Aluno alunos[MAX_ALUNOS];
    int n = 0;

    while (fscanf(file, "%49s %c%d", alunos[n].nome, &alunos[n].turno, &alunos[n].serie) == 3) {
        n++;
    }
    fclose(file);

    for (int serie = 6; serie <= 8; serie++) {
        exibeAlunosPorTurnoESerie(alunos, n, 'M', serie);
        exibeAlunosPorTurnoESerie(alunos, n, 'T', serie);
    }

    return 0;
}
