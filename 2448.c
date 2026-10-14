#include <stdio.h>
#include <stdlib.h>

int buscaBinariaIterativa(int v[], int tamanho, int alvo) {
    int esq = 0;
    int dir = tamanho - 1;

    while (esq <= dir) {
        int meio = esq + (dir - esq) / 2;

        if (v[meio] == alvo) {
            return meio;
        }

        if (v[meio] < alvo) {
            esq = meio + 1;
        } 
        else {
            dir = meio - 1;
        }
    }

    return -1;
}

int main() {
    int n, m;
    
    scanf("%d %d", &n, &m);
    
    if (n <= 1)
    {
        printf("0\n");
        return 0;
    }
    
    int *casas = (int *)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &casas[i]);
    }

    int pos = 0; 
    int total = 0; 

    for (int i = 0; i < m; i++) {
        int encomenda;
        scanf("%d", &encomenda);

        int pos2 = buscaBinariaIterativa(casas, n, encomenda);

        total += abs(pos2 - pos);

        pos = pos2;
    }

    printf("%d\n", total);

    free(casas);

    return 0;

}
