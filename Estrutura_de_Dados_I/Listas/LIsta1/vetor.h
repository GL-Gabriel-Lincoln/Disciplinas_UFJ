#ifndef VETOR_H
#define VETOR_H

typedef struct
{
    int *data;
    int size;
} Vetor;

Vetor *cria(int size);
void libera(Vetor *v);
Vetor *soma(Vetor *v1, Vetor *v2);
int prodInterno(Vetor *v1, Vetor *v2);
Vetor *prodVet(Vetor *v1, Vetor *v2);

#endif // VETOR_H
