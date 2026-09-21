#include <stdlib.h>
#include <stdio.h>

struct node
{
    int valor;
    struct node *anterior, *proximo;
};

struct fila_dupla
{
    int tamanho;
    struct node *frente, *tras;
};

void enfileira(struct fila_dupla *d, int valor)
{
    d->tamanho += 1;
    struct node *novo_no = (struct node *)malloc(sizeof(struct node));

    novo_no->valor = valor;
    novo_no->anterior = d->tras;
    novo_no->proximo = NULL;
    if (d->tras != NULL)
        d->tras->proximo = novo_no;
    d->tras = novo_no;
    if (d->frente == NULL)
        d->frente = d->tras;
}

void desinfilleira(struct fila_dupla *d)
{
    if (d->tamanho > 0)
    {
        d->tamanho -= 1;
        struct node *velha_frente = d->frente;
        d->frente = d->frente->proximo;
        if (d->frente != NULL)
            d->frente->anterior = NULL;
        else
            d->tras = NULL;
        free(velha_frente);
    }
}

int pega_frente(struct fila_dupla *d)
{
    return d->frente->valor;
}

int obtem_tamanho(struct fila_dupla *d)
{
    return d->tamanho;
}

int esta_vazia(struct fila_dupla *d)
{
    return d->tamanho == 0;
}

void inicializa_fila(struct fila_dupla *d)
{
    d->tamanho = 0;
    d->frente = NULL;
    d->tras = NULL;
}

void limpa_fila(struct fila_dupla *d)
{
    while (!esta_vazia(d))
    {
        desinfilleira(d);
    }
}

int main()
{
    int n, primeiro;
    struct fila_dupla cartas;

    while (scanf("%d", &n) != EOF)
    {
        if (n == 0)
            break;

        inicializa_fila(&cartas);

        for (int i = 1; i <= n; ++i)
        {
            enfileira(&cartas, i);
        }

        primeiro = 1;
        printf("Discarded cards:");
        
        while (obtem_tamanho(&cartas) > 1)
        {
            if (!primeiro)
                printf(",");
            
            int discard = pega_frente(&cartas);
            printf(" %d", discard);
            primeiro = 0;

            desinfilleira(&cartas);

            int prox = pega_frente(&cartas);
            desinfilleira(&cartas);
            enfileira(&cartas, prox);
        }
        
        printf("\nRemaining card: %d\n", pega_frente(&cartas));

        limpa_fila(&cartas);
    }

    return 0;
}
