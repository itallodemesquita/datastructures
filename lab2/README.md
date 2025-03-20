# Laboratório II - Algoritmos e Estruturas de Dados I

## Registros em C
Registros (structs) são uma das formas de agrupar diferentes tipos de dados sob um único nome. Eles permitem a criação de tipos de dados complexos, que podem conter múltipos campos de diferentes tipos de dados. São muito úteis para organizar dados relacionados e facilitar o acesso e manipulação desses dados.

``` c
#include <stdio.h>

// Definição de uma struct chamada Pessoa
struct Pessoa {
    char nome[50];
    int idade;
    float altura;
};

int main() {
    // Declaração de uma variável do tipo struct Pessoa
    struct Pessoa pessoa1;

    // Atribuição de valores aos campos da struct
    strcpy(pessoa1.nome, "João");
    pessoa1.idade = 30;
    pessoa1.altura = 1.75;

    // Exibição dos valores dos campos da struct
    printf("Nome: %s\n", pessoa1.nome);
    printf("Idade: %d\n", pessoa1.idade);
    printf("Altura: %.2f\n", pessoa1.altura);

    return 0;
}
```

### Como criar um ponteiro de um registro?
Você deve declarar um ponteiro do tipo `struct` e atribuir o endereço da variável a esse ponteiro. Isso pode ser feito da seguinte forma:

```c
/* Criando um ponteiro para pessoa1 */
struct Pessoa *ptr = &pessoa1;
```

Este código:
1. Declara o ponteiro `*ptr` para o registro `struct Pessoa`.
2. `*ptr = &pessoa1` atribui o endereço de `pessoa1` ao ponteiro declarado.
3. Permite com que os campos de `struct` sejam acessados pelo ponteiro utilizando o operador `->`, dessa forma:

```c
// Exibindo os valores dos campos da variável p1 através do ponteiro ptr
printf("\n\nExibindo dados através do ponteiro ptr: \n");
printf("Nome: %s\n", ptr->nome);
printf("Idade: %.2f\n", ptr->idade);
printf("Altura: %d\n", ptr->altura);
```

### O que acontece quando acessamos um ponteiro com endereço inválido?
Quando acessamos um ponteiro com endereço inválido, o comportamento do programa é indefinido. Isso pode causar vários problemas, como:

1. **Erros de segmentação (segmentation faults)**: O programa pode tentar acessar uma área de memória que não está permitida, resultando em um erro de segmentação e a interrupção do programa.
2. **Dados corrompidos**: O programa pode acessar ou modificar dados incorretos, levando a resultados inesperados ou corrompidos.
3. **Comportamento imprevisível**: O programa pode se comportar de maneira errática, já que está acessando memória que não deveria.

Para evitar esses problemas, é importante sempre inicializar ponteiros e verificar se eles contêm endereços válidos antes de acessá-los.
