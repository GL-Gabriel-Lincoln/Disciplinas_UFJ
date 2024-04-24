#ifndef VECTOR_H
#define VECTOR_H

typedef struct
{
    int *data;
    int size;
} Vector;

Vector *create(int size);
void freeVector(Vector *v);
Vector *add(Vector *v1, Vector *v2);
int innerProduct(Vector *v1, Vector *v2);
Vector *crossProduct(Vector *v1, Vector *v2);

#endif
