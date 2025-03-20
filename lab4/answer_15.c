#include <stdio.h>

int main() {
    FILE *texto, *binario;
    int i;

    // Abrindo o arquivo texto para escrita
    texto = fopen("numbers.txt", "w");
    if (texto == NULL) {
        perror("O arquivo não foi encontrado!\n");
        return 1;
    }

    // Abrindo o arquivo binário para escrita
    binario = fopen("numbers.bin", "wb");
    if (binario == NULL) {
        perror("O arquivo não foi encontrado!\n");
        fclose(texto);
        return 1;
    }

    // Escrevendo os números de 1 a 100 nos dois arquivos
    for (i = 1; i <= 100; i++) {

        // Escreve no arquivo texto
        fprintf(texto, "%d\n", i);

        // Escreve no arquivo binário
        fwrite(&i, sizeof(int), 1, binario);
    }

    // Fechando os arquivos
    fclose(texto);
    fclose(binario);

    return 0;
}

/*
Comparação dos tamanhos dos arquivos:
- O arquivo texto ("numbers.txt") conterá os números em formato legível, com cada número seguido por um caractere de nova linha. Cada número pode ocupar de 1 a 3 bytes (para números de 1 a 100), mais 1 byte para o caractere de nova linha. Portanto, o tamanho total do arquivo texto será maior devido ao armazenamento dos caracteres adicionais.
- O arquivo binário ("numbers.bin") armazenará os números em formato binário, onde cada número é representado por 4 bytes (assumindo que sizeof(int) é 4 bytes). O tamanho total do arquivo binário será 100 * 4 bytes = 400 bytes.
- Em geral, o arquivo binário será menor que o arquivo texto porque não inclui caracteres adicionais como espaços ou novas linhas, e os números são armazenados em seu formato binário nativo.
*/