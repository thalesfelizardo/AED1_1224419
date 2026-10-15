#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int info;
    struct No *embaixo;
} No;

typedef struct pilha {
    int tamanho;
    No *topo;
} pilha;

void inicializar(pilha *p) {
    p->tamanho = 0;
    p->topo = NULL;
}

void push(pilha *p, int x) {
    No *n = (No*)malloc(sizeof(No));
    if (n == NULL) {
        return;
    }

    p->tamanho += 1;
    n->info = x;
    n->embaixo = p->topo;
    p->topo = n;
}

int pop(pilha *p) {
    if (p->topo == NULL) {
        return -1; 
    }
    
    p->tamanho -= 1;
    No *temp = p->topo;          
    int valor = temp->info;     
    
    p->topo = p->topo->embaixo;    
    free(temp);                 
    
    return valor;
}

int top(struct pilha* p) {
    if (p->topo == NULL) return -1;
    return p->topo->info;
}

int empty(struct pilha* p) {
    return p->tamanho == 0;
}

void destroi(struct pilha* p) {
    while(!empty(p)) {
        pop(p);
    }
}

int main() {
    int N;

    while (scanf("%d", &N) && N != 0) {
        int x;
        
      
        while (scanf("%d", &x) && x != 0) {
            int alvo[N];
            alvo[0] = x;
            
            for (int i = 1; i < N; i++) {
                scanf("%d", &alvo[i]);
            }

            pilha estacao;
            inicializar(&estacao);

            int comboio_atual = 1;
            int indice_alvo = 0;

            while (comboio_atual <= N) {
                push(&estacao, comboio_atual);
                comboio_atual++;

               
                while (!empty(&estacao) && top(&estacao) == alvo[indice_alvo]) {
                    pop(&estacao);
                    indice_alvo++;
                }
            }

            if (empty(&estacao)) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }

            destroi(&estacao);
        }
        printf("\n"); 
    }

    return 0;
}
