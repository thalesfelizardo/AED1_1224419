#include <stdio.h>
#include <stdlib.h>

int verificaquadrado(int matriz[9][9], int x);
int verificalinhas(int matriz[9][9], int linha);
int verificacolunas(int matriz[9][9], int coluna);

int main()
{
    int matriz[9][9];
    int qtd;
    scanf("%d", &qtd);
    for (int index = 0; index < qtd; index++)
    {
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                scanf("%d", &matriz[i][j]);

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
    return 0;
}

int verificalinhas(int matriz[9][9], int linha){
    int veteste[10];

    for(int i = 0; i < 10; ++i){
        veteste[i] = 0;
    }

    for(int i = 0; i < 9; ++i){
        if(veteste[matriz[linha][i]]){
            return 0;
        }
        veteste[matriz[linha][i]] += 1;
    }

    return 1;
}

int verificacolunas(int matriz[9][9], int coluna)
{
    int veteste[10] = {0};
    for (int i = 0; i < 9; i++)
    {
        int valor = matriz[i][coluna];
        if (veteste[valor]) return 0;
        veteste[valor] = 1;
    }
    return 1;
}

int verificaquadrado(int matriz[9][9], int x)
{
    int veteste[10] = {0};
    int linha  = 3 * (x / 3);
    int coluna = 3 * (x % 3);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            int valor = matriz[linha + i][coluna + j];
            if (veteste[valor]) return 0;
            veteste[valor] = 1;
        }
    return 1;
}
