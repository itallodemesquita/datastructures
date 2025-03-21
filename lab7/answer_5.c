/* Questão 5 - Laboratório VII */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para representar uma música
typedef struct Musica {
    char titulo[50];
    char artista[50];
    int duracao; // duração em segundos
    struct Musica* prox;
    struct Musica* ant;
} Musica;

// Estrutura para representar a playlist
typedef struct Playlist {
    Musica* atual;
} Playlist;

// Função para criar uma nova música
Musica* criarMusica(char* titulo, char* artista, int duracao) {
    Musica* novaMusica = (Musica*)malloc(sizeof(Musica));
    strcpy(novaMusica->titulo, titulo);
    strcpy(novaMusica->artista, artista);
    novaMusica->duracao = duracao;
    novaMusica->prox = novaMusica;
    novaMusica->ant = novaMusica;
    return novaMusica;
}

// Função para adicionar uma música à playlist
void adicionarMusica(Playlist* playlist, Musica* novaMusica) {
    if (playlist->atual == NULL) {
        playlist->atual = novaMusica;
    } else {
        Musica* ultima = playlist->atual->ant;
        ultima->prox = novaMusica;
        novaMusica->ant = ultima;
        novaMusica->prox = playlist->atual;
        playlist->atual->ant = novaMusica;
    }
}

// Função para remover uma música da playlist
void removerMusica(Playlist* playlist, char* titulo) {
    if (playlist->atual == NULL) return;

    Musica* temp = playlist->atual;
    do {
        if (strcmp(temp->titulo, titulo) == 0) {
            if (temp->prox == temp) {
                free(temp);
                playlist->atual = NULL;
                return;
            } else {
                temp->ant->prox = temp->prox;
                temp->prox->ant = temp->ant;
                if (temp == playlist->atual) {
                    playlist->atual = temp->prox;
                }
                free(temp);
                return;
            }
        }
        temp = temp->prox;
    } while (temp != playlist->atual);
}

// Função para exibir a playlist atual
void exibirPlaylist(Playlist* playlist) {
    if (playlist->atual == NULL) {
        printf("A playlist está vazia.\n");
        return;
    }

    Musica* temp = playlist->atual;
    do {
        printf("Título: %s, Artista: %s, Duração: %d segundos\n", temp->titulo, temp->artista, temp->duracao);
        temp = temp->prox;
    } while (temp != playlist->atual);
}

// Função para reorganizar a playlist
void reorganizarPlaylist(Playlist* playlist, int posicaoAtual, int novaPosicao) {
    if (playlist->atual == NULL || posicaoAtual == novaPosicao) return;

    Musica* temp = playlist->atual;
    Musica* musicaMover = NULL;
    int contador = 0;

    // Encontrar a música na posição atual
    do {
        if (contador == posicaoAtual) {
            musicaMover = temp;
            break;
        }
        temp = temp->prox;
        contador++;
    } while (temp != playlist->atual);

    if (musicaMover == NULL) return;

    // Remover a música da posição atual
    musicaMover->ant->prox = musicaMover->prox;
    musicaMover->prox->ant = musicaMover->ant;

    // Inserir a música na nova posição
    temp = playlist->atual;
    contador = 0;
    do {
        if (contador == novaPosicao) {
            musicaMover->prox = temp;
            musicaMover->ant = temp->ant;
            temp->ant->prox = musicaMover;
            temp->ant = musicaMover;
            if (novaPosicao == 0) {
                playlist->atual = musicaMover;
            }
            return;
        }
        temp = temp->prox;
        contador++;
    } while (temp != playlist->atual);
}

// Função principal para testar a playlist
int main() {
    Playlist playlist = {NULL};

    adicionarMusica(&playlist, criarMusica("Su Veneno", "Romeo Santos", 210));
    adicionarMusica(&playlist, criarMusica("I Fell So Good Today", "Charlie Brown Jr", 180));
    adicionarMusica(&playlist, criarMusica("Bed Chem", "Sabrina Carpenter", 240));

    printf("Playlist inicial:\n");
    exibirPlaylist(&playlist);

    printf("\nReorganizando a playlist:\n");
    reorganizarPlaylist(&playlist, 0, 2);
    exibirPlaylist(&playlist);

    printf("\nRemovendo uma música:\n");
    removerMusica(&playlist, "I Fell So Good Today");
    exibirPlaylist(&playlist);

    return 0;
}