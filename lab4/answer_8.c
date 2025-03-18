#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUNOS 100
#define MAX_NOME 50

// Estrutura para representar um aluno
typedef struct {
    char nome[MAX_NOME];
    char turno; // 'M' ou 'T'
    int serie;  // 6, 7 ou 8
} Aluno;

// Função para ler alunos do arquivo
int lerAlunos(const char *nomeArquivo, Aluno alunos[]) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 0;
    }

    int i = 0;
    while (fscanf(arquivo, "%49s %c%d", alunos[i].nome, &alunos[i].turno, &alunos[i].serie) == 3) {
        i++;
        if (i >= MAX_ALUNOS) {
            printf("Limite de alunos atingido. Apenas os primeiros %d alunos foram lidos.\n", MAX_ALUNOS);
            break;
        }
    }

    fclose(arquivo);
    return i;
}

// Função para exibir alunos por turno e série
void exibirAgrupadosPorTurnoESerie(Aluno alunos[], int totalAlunos) {
    const char *turnos[] = {"Manhã", "Tarde"};
    for (int t = 0; t < 2; t++) {
        char turno = t == 0 ? 'M' : 'T';
        printf("\nAlunos do turno %s:\n", turnos[t]);

        for (int serie = 6; serie <= 8; serie++) {
            printf("  Série %d:\n", serie);
            for (int i = 0; i < totalAlunos; i++) {
                if (alunos[i].turno == turno && alunos[i].serie == serie) {
                    printf("    - %s\n", alunos[i].nome);
                }
            }
        }
    }
}

int main() {
    Aluno alunos[MAX_ALUNOS];
    const char *nomeArquivo = "text_files/escola.txt";

    // Ler alunos do arquivo
    int totalAlunos = lerAlunos(nomeArquivo, alunos);
    if (totalAlunos == 0) {
        printf("Nenhum aluno foi lido do arquivo.\n");
        return 1;
    }

    // Exibir alunos agrupados por turno e série
    exibirAgrupadosPorTurnoESerie(alunos, totalAlunos);

    return 0;
}
