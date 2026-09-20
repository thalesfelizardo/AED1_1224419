#include <stdio.h>
#include <stdlib.h>
#define VET 100

int main()
{
    int *vetor;
    int index = 1; 
    int i;
    int maior;
    
    vetor = (int *) malloc(VET * sizeof(int));
    
    if (vetor == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }
    
    for(i = 0; i < VET; i++){
        scanf("%d", &vetor[i]);
    }
    
    maior = vetor[0];
    index = 1;
    
        for(i = 0; i < VET; i++){
        if(vetor[i] > maior){
            maior = vetor[i];
            index = i + 1;
        }
    }
    
    printf("%d\n%d\n", maior, index);
    
    free(vetor);
    
    return 0;
}
