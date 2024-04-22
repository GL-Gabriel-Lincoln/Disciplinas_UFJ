#include <stdlib.h>
#include "vetor.h"

Vetor *cria(int size)
{
    Vetor *v = (Vetor *)malloc(sizeof(Vetor));
    v->data = (int *)malloc(size * sizeof(int));
    v->size = size;
    return v;
}

void libera(Vetor *v)
{
    free(v->data);
    free(v);
}

Vetor *soma(Vetor *v1, Vetor *v2)
{
    if (v1->size != v2->size)
    {
        return NULL;
    }
    Vetor *v = cria(v1->size);
    for (int i = 0; i < v1->size; i++)
    {
        v->data[i] = v1->data[i] + v2->data[i];
    }
    return v;
}

int prodInterno(Vetor *v1, Vetor *v2)
{

    int produto = 0;
    for (int i = 0; i < v1->size; i++)
    {
        produto += v1->data[i] * v2->data[i];
    }
    return produto;
}

Vetor *prodVet(Vetor *v1, Vetor *v2)
{

    if (v1->size != 3 || v2->size != 3)
    {
        return NULL;
    }
    Vetor *v = cria(3);
    v->data[0] = v1->data[1] * v2->data[2] - v1->data[2] * v2->data[1];
    v->data[1] = v1->data[2] * v2->data[0] - v1->data[0] * v2->data[2];
    v->data[2] = v1->data[0] * v2->data[1] - v1->data[1] * v2->data[0];
    return v;
}

int main()
{

    Vetor *v1 = cria(3);
    Vetor *v2 = cria(3);

    for (int i = 0; i < 3; i++)
    {
        v1->data[i] = i + 1;
        v2->data[i] = (i + 1) * 10;
    }

    Vetor *somaVetor = soma(v1, v2);

    int produtoInterno = prodInterno(v1, v2);

    Vetor *produtoVetorial = prodVet(v1, v2);

    printf("Soma: ");
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", somaVetor->data[i]);
    }
    printf("\n");

    printf("Produto interno: %d\n", produtoInterno);

    printf("Produto vetorial: ");
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", produtoVetorial->data[i]);
    }
    printf("\n");

    libera(v1);
    libera(v2);
    libera(somaVetor);
    libera(produtoVetorial);

    return 0;
}