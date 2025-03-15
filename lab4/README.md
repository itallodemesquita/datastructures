# Laboratory IV - Ítallo de Mesquita

Nesta pasta, estão todos os códigos e resoluções utilizadas para responder a lista de Laboratório da disciplina de Algoritmos e Estrutura de Dados I da UFERSA Pau dos Ferros, ministrada pelo prof. George Felipe no semestre 2024.3.


### 1) Considerando o arquivo texto apresentado, o que o trecho de código abaixo faz?

Arquivo de texto [intro.txt](text_files/intro.txt):
> A leitura de arquivos pode ser realizada por caractere, por palavras ou por linhas.

O código:
```
#include <stdio.h>
#include <stdlib.h>

int main() {

FILE *fin;
fin = fopen("intro.txt", "r"); /* Abre o arquivo em 'read mode' */
char ch;

fscanf(fin, "%c", &ch); /* Lê um caractere */
fclose(fin);

printf("%c\n", ch);

return 0;

}
```

- Inicialmente, o código declara um ponteiro `*fin` do tipo `FILE`;
- No comando `fin = fopen("intro.txt", "r");` a função `fopen` serve para abrir o arquivo `intro.txt` em modo leitura (`r`);
    - Caso o arquivo não exista, a função retorna `NULL`;
- O programa declara uma variável `char ch` como buffer;
    - Em seguida, a função `fscanf` lê um caractere do arquivo `*fin` e armazena em `ch`. Após a leitura, o código solicita o fechamento do arquivo para liberar recurso do sistema operacional.
- Por fim, o comando `printf("%c\n", ch);` imprime no terminal o caractere que foi lido do arquivo.

Em conclusão, esse programa sempre armazena em `ch` o primeiro caractere do arquivo, desde que o mesmo não esteja vazio, pois a função faz apenas uma chamada de leitura. Ou seja, nessa conjuntura, o código retornaria o caractere 'A'.

#### a) Lendo o oitavo caractere do arquivo

Para permitir que essa ação ocorra, o cursor do arquivo deve ser movido até a posição do caractere nº 8, utilizando a função `fseek()` da seguinte forma:

```
FILE *fin = fopen("intro.txt", "r");
char ch;

fseek(fin, 7, SEEK_SET); /* Move o cursor para o índice 7  */

fscanf(fin, "c%", &ch); /* Lê o caractere na posição determinada */
```

#### b) Lendo uma palavra (string) do arquivo

Para isto, deve-se utilizar a função fscanf recebendo um dado `%s` (string) como parâmetro. Neste caso, a leitura acontecerá até que seja identificado um espaço, tabulação ou quebra de linha.
Além disso, deve ser criado um buffer do tipo `char` para armazenar a palavra lida.

```
FILE *fin = fopen("intro.txt", "r");
char palavra[100];  // buffer para armazenar a palavra

fscanf(fin, "%s", palavra);  // lê a primeira palavra
fclose(fin);

printf("Palavra lida: %s\n", palavra);
```

Dessa forma, o código retornaria a primeira palavra do documento de texto.

#### c) Lendo a quinta palavra do arquivo

Para identificar a quinta palavra do arquivo, pode-se usar um loop com um índice que identifique e leia a palavra de número 5 da seguinte forma:

```
while (fscanf(fin, "%s", palavra) == 1) {
    i++;

    if (i == 5) {
        printf("A 5ª palavra é: %s\n", palavra);
        break; /* Encerra o loop */
        }
    }
```

- No loop `while (fscanf(fin, "%s", palavra) == 1)`, o programa lê cada uma das palavras, até chegar ao fim do arquivo, enquanto a leitura for bem-sucedida. Enquano isso, o índice conta o número de palavras lidas;
- Na condicional `if (i == 5)`, quando o loop lê a quinta palavra, o programa guarda-a no buffer e a imprime. Feito isso, o comando `break` interrompe a execução do loop.

#### d) Lendo uma linha do arquivo

Para realizar essa ação, utiliza-se a função `fgets`, que lê um arquivo até a próxima quebra de linha ou ao atingir o limite do buffer, da seguinte forma:

```
FILE *fin = fopen("intro.txt", "r");
char linha[200];  // Buffer para armazenar a linha

// Lê a primeira linha inteira do arquivo
if (fgets(linha, sizeof(linha), fin) != NULL) {
    printf("Linha lida: %s", linha);
    }

fclose(fin);
```

- No comando `fgets(linha, sizeof(linha), fin)`, os parâmetros são:
    - `linha`, que indica o buffer onde a linha vai ser armazenada;
    - `sizeof(linha)`, que indica o tamanho da linha que será lida (tamanho da string);
    - `fin`, aponta o arquivo aberto;

    ### 2) Considerando o arquivo texto [weather.txt](text_files/intro.txt), escreva um programa para ler todos os números do texto e gravá-los em outro arquivo.