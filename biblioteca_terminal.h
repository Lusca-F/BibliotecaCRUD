#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINHAS 24
#define COLUNAS 80

// Função para limpar a tela do terminal
void limpar_tela() {
    system("cls");
}

// Função para exibir o título centralizado
void exibir_titulo_centralizado(char *titulo) {
    int titulo_length = strlen(titulo);
    int titulo_pos = (COLUNAS - titulo_length) / 2;
    printf("%*s%s\n", titulo_pos, "", titulo);
}

// Função para criar uma janela
void janela(int lin_inicial, int col_inicial, int lin_final, int col_final, char *titulo, int tipo_moldura) {
    limpar_tela();
    exibir_titulo_centralizado(titulo);

    int i, j;
    if (tipo_moldura == 1) {
        for (j = 0; j < COLUNAS; j++) {
            printf("-");
        }
        printf("\n");
    }

    for (i = 0; i < lin_final - lin_inicial - 1; i++) {
        printf("|");
        for (j = 1; j < COLUNAS - 1; j++) {
            printf(" ");
        }
        printf("|\n");
    }

    if (tipo_moldura == 1) {
        for (j = 0; j < COLUNAS; j++) {
            printf("-");
        }
        printf("\n");
    }
}

// Função para exibir um rótulo
void label(int lin, int col, char *texto) {
    printf("\033[%d;%dH%s", lin, col, texto);
}

// Função para ler uma string
char *ler_string(int lin, int col, int tamanho) {
    char *input_str = (char *)malloc((tamanho + 1) * sizeof(char));
    printf("\033[%d;%dH", lin, col);
    fgets(input_str, tamanho + 1, stdin);
    input_str[strcspn(input_str, "\n")] = '\0';
    return input_str;
}

// Função para ler um inteiro
int ler_inteiro(int lin, int col, int tamanho) {
    char *input_str = ler_string(lin, col, tamanho);
    int input_int = atoi(input_str);
    free(input_str);
    return input_int;
}

// Função para ler um decimal
float ler_decimal(int lin, int col, int tamanho) {
    char *input_str = ler_string(lin, col, tamanho);
    float input_float = atof(input_str);
    free(input_str);
    return input_float;
}
