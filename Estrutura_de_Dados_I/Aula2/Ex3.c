typedef struct
{
    int *elements;
    int size;
} Vetor;

void inicializaVetor(Vetor *v, int size);
void insereElemento(Vetor *v, int element);
void removeElemento(Vetor *v, int element);
int obtemElemento(Vetor *v, int position);
