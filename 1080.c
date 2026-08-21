#define TAM 100
#include <stdio.h>

int main(){

    int vetor[TAM];
    int maior = 0;
    int pos = 0;

    for (size_t i = 0; i < TAM; i++)
    {
        scanf("%d", &vetor[i]);
    }   
    
    maior = vetor[0];
    
    for (size_t j = 0; j < TAM; j++)
    {
        if (vetor[j] > maior)
        {
            maior = vetor[j];
            pos = j + 1;
        }
    }
 
    printf("%d\n%d\n", maior, pos);

    return 0;
}
