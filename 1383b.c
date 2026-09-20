#include <stdio.h>
#include <stdlib.h>

int verificaquadrado(int **matriz, int x);
int verificalinhas(int **matriz, int linha);
int verificacolunas(int **matriz, int coluna);

int main()
{
    int qtd;
    if (scanf("%d", &qtd) != 1) return 0;

    int **matriz = (int **) malloc(9 * sizeof(int *));
    if (matriz == NULL) {
        printf("Erro ao alocar memoria para as linhas!\n");
        return 1;
    }

    for (int i = 0; i < 9; i++) {
        matriz[i] = (int *) malloc(9 * sizeof(int));
        if (matriz[i] == NULL) {
            printf("Erro ao alocar memoria para as colunas!\n");
            return 1;
        }
    }

    for (int index = 0; index < qtd; index++)
    {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &matriz[i][j]);
            }
        }

        int valido = 1;
        for (int i = 0; i < 9; i++)
        {
            if (!verificalinhas(matriz, i)){
                valido = 0;
            }  
            if (!verificacolunas(matriz, i)){
                valido = 0;
            }

            if (!verificaquadrado(matriz, i))
            {
                valido = 0;
            }    
        }

        printf("Instancia %d\n", index + 1);
        if (valido)
        {
            printf("SIM\n");
        }
        else{
            printf("NAO\n");
        }
        
        printf("\n");
    }

    for (int i = 0; i < 9; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}

int verificalinhas(int **matriz, int linha)
{
    int veteste[10] = {0};
    for (int j = 0; j < 9; j++)  
    {
        int valor = matriz[linha][j];
        if (valor < 1 || valor > 9 || veteste[valor]) return 0;
        veteste[valor] = 1;
    }
    return 1;
}

int verificacolunas(int **matriz, int coluna)
{
    int veteste[10] = {0};
    for (int i = 0; i < 9; i++)
    {
        int valor = matriz[i][coluna];
        if (valor < 1 || valor > 9 || veteste[valor]) return 0;
        veteste[valor] = 1;
    }
    return 1;
}

int verificaquadrado(int **matriz, int x)
{
    int veteste[10] = {0};
    int linha  = 3 * (x / 3);
    int coluna = 3 * (x % 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
        {
            int valor = matriz[linha + i][coluna + j];
            if (valor < 1 || valor > 9 || veteste[valor]) return 0;
            veteste[valor] = 1;
        }
    }
    return 1;
}
