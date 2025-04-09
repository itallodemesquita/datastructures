# Ponteiros e Registros em C

Este é um guia de referência rápida para o estudo de ponteiros e registros na linguagem C, baseado no conteúdo da disciplina de Algoritmos e Estrutura de Dados I da UFERSA - Campus Pau dos Ferros. Nesta pasta, estão todos os códigos e resoluções, escritos por mim, utilizadas para responder a lista de exercícios da disciplina. Façam um bom proveito!

---

## 📌 O que são Ponteiros?

Um **ponteiro** é uma variável que armazena o **endereço de memória** de outra variável.

### 🔧 Sintaxe básica:
```c
int x = 10;
int *ptr = &x;  // ptr aponta para x
```

### 📌 Desreferenciação:
```c
printf("%d", *ptr);  // imprime o valor de x (10)
```

---

## 🧠 Principais usos de ponteiros:
- Guardar o endereço de variáveis
- Evitar cópias grandes em funções
- Acessar/alterar dados via referência
- Trabalhar com arrays, strings e estruturas

---

## 🧱 Ponteiros e Registros (Structs)

Você pode criar ponteiros para tipos definidos pelo programador:

```c
typedef struct {
    char nome[50];
    int idade;
} Pessoa;

Pessoa p = {"Ana", 30};
Pessoa *ptr = &p;

printf("%s", ptr->nome);  // Acessa com operador ->
```

| Acesso direto | Acesso via ponteiro |
|---------------|---------------------|
| `p.nome`      | `ptr->nome`         |

---

## 🔁 Ponteiros Dinâmicos vs. Estáticos

| Conceito           | Exemplo                        |
|--------------------|--------------------------------|
| Ponteiro para vetor| `int *p = vetor;`              |
| Vetor como ponteiro| `vetor[0] == *(p + 0)`         |

---

## 🔤 Ponteiros e Strings

```c
char *nome = "Kyara";      // ponteiro para string literal
const char *msg = "Oi";    // não pode ser modificado
```

> `*ptr` pode apontar para o início de uma string, mas não deve alterar literais se forem `const`.

---

## 🧩 Ponteiros e Funções

- Permite **passar referência** de variáveis para funções
- Evita cópia de dados grandes
- Permite **modificar os dados originais**

### Exemplo:
```c
void alterar(int *num) {
    *num = 100;
}

int x = 5;
alterar(&x);
// x agora é 100
```

---

## ➕ Aritmética de Ponteiros

Você pode usar operações como:
- `ptr++` → avança para o próximo elemento
- `*(ptr + i)` → equivalente a `array[i]`

---

## ✅ Resumo Final

| Recurso                     | Uso                                    |
|-----------------------------|-----------------------------------------|
| `int *p`                    | Ponteiro para inteiro                   |
| `*p`                        | Valor apontado                          |
| `&var`                      | Endereço de `var`                       |
| `struct s *ptr`             | Ponteiro para struct                    |
| `ptr->campo`                | Acesso a campo da struct via ponteiro  |
| `f(&x)`                     | Passa referência para função            |

---

📚 **Recomendado para estudo**:
- Praticar com vetores e structs
- Passagem por referência em funções
- Manipulação de strings via ponteiros

---

🧑‍🏫 Prof. George Felipe  
📅 26 de fevereiro de 2025  
📘 Algoritmos e Estrutura de Dados I