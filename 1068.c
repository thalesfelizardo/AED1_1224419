#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct node
{
    char valor;
    struct node *tras;
};

struct pilha
{
    int tamanho;
    struct node *topo;
};

void empilha(struct pilha *p, char valor)
{
    p->tamanho += 1;
    struct node *novo_topo = (struct node *)malloc(sizeof(struct node));

    novo_topo->valor = valor;
    novo_topo->tras = p->topo;
    p->topo = novo_topo;
}

void desempilha(struct pilha *p)
{
    if (p->tamanho > 0)
    {
        p->tamanho -= 1;
        struct node *velho_topo = p->topo;
        p->topo = p->topo->tras;
        free(velho_topo);
    }
}

char pega_topo(struct pilha *p)
{
    return p->topo->valor;
}

int tamanho_pilha(struct pilha *p)
{
    return p->tamanho;
}

int pilha_vazia(struct pilha *p)
{
    return p->tamanho == 0;
}

void inicializa_pilha(struct pilha *p)
{
    p->tamanho = 0;
    p->topo = NULL;
}

void limpa_pilha(struct pilha *p)
{
    while (!pilha_vazia(p))
    {
        desempilha(p);
    }
}

int main()
{
    int i, tam;
    struct pilha p;
    char expressao[1001];

    while (scanf("%s", expressao) != EOF)
    {
        inicializa_pilha(&p);
        tam = strlen(expressao);

        for (i = 0; i < tam; ++i)
        {
            if (expressao[i] == '(')
            {
                empilha(&p, '(');
            }
            else if (expressao[i] == ')')
            {
                if (pilha_vazia(&p))
                    break;
                else
                    desempilha(&p);
            }
        }

        if (i == tam && pilha_vazia(&p))
            printf("correct\n");
        else
            printf("incorrect\n");

        limpa_pilha(&p);
    }

    return 0;
}
