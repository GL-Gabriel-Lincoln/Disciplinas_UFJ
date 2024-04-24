#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

Vector *create(int size)
{
    Vector *v = (Vector *)malloc(sizeof(Vector));
    v->data = (int *)malloc(size * sizeof(int));
    v->size = size;
    return v;
}

void freeVector(Vector *v)
{
    free(v->data);
    free(v);
}

Vector *add(Vector *v1, Vector *v2)
{
    if (v1->size != v2->size)
    {
        return NULL;
    }
    Vector *v = create(v1->size);
    for (int i = 0; i < v1->size; i++)
    {
        v->data[i] = v1->data[i] + v2->data[i];
    }
    return v;
}

int innerProduct(Vector *v1, Vector *v2)
{
    int product = 0;
    for (int i = 0; i < v1->size; i++)
    {
        product += v1->data[i] * v2->data[i];
    }
    return product;
}

Vector *crossProduct(Vector *v1, Vector *v2)
{
    if (v1->size != 3 || v2->size != 3)
    {
        return NULL;
    }
    Vector *v = create(3);
    v->data[0] = v1->data[1] * v2->data[2] - v1->data[2] * v2->data[1];
    v->data[1] = v1->data[2] * v2->data[0] - v1->data[0] * v2->data[2];
    v->data[2] = v1->data[0] * v2->data[1] - v1->data[1] * v2->data[0];
    return v;
}

int main()
{
    Vector *v1 = create(3);
    Vector *v2 = create(3);

    for (int i = 0; i < 3; i++)
    {
        v1->data[i] = i + 1;
        v2->data[i] = (i + 1) * 10;
    }

    Vector *vectorSum = add(v1, v2);

    int innerProductResult = innerProduct(v1, v2);

    Vector *crossProductResult = crossProduct(v1, v2);

    printf("Soma: ");
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", vectorSum->data[i]);
    }
    printf("\n");

    printf("Produto interno: %d\n", innerProductResult);

    printf("Produto vetorial: ");
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", crossProductResult->data[i]);
    }
    printf("\n");

    freeVector(v1);
    freeVector(v2);
    freeVector(vectorSum);
    freeVector(crossProductResult);

    return 0;
}