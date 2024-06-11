#include <stdio.h>
#include <stdlib.h>

typedef struct Livro {
    int codigo;
    struct Livro* proximo;
} Livro;

typedef struct Prateleira {
    Livro* livros;
} Prateleira;

Prateleira estante[10]; 

void inserirLivro(int prateleira, int codigo) {
    Livro* novoLivro = (Livro*) malloc(sizeof(Livro));
    novoLivro->codigo = codigo;
    novoLivro->proximo = estante[prateleira].livros;
    estante[prateleira].livros = novoLivro;
}

Livro* consultarLivro(int prateleira, int codigo) {
    Livro* livro = estante[prateleira].livros;
    while (livro != NULL) {
        if (livro->codigo == codigo) {
            return livro;
        }
        livro = livro->proximo;
    }
    return NULL;
}

void retirarLivro(int prateleira, int codigo) {
    Livro* livro = estante[prateleira].livros;
    Livro* anterior = NULL;
    while (livro != NULL) {
        if (livro->codigo == codigo) {
            if (anterior == NULL) {
                estante[prateleira].livros = livro->proximo;
            } else {
                anterior->proximo = livro->proximo;
            }
            free(livro);
            return;
        }
        anterior = livro;
        livro = livro->proximo;
    }
}

int main() {

    inserirLivro(0, 101);
    inserirLivro(0, 102);

    Livro* livro = consultarLivro(0, 101);
    if (livro != NULL) {
        printf("Livro encontrado com o código: %d\n", livro->codigo);
    } else {
        printf("Livro não encontrado.\n");
    }

    retirarLivro(0, 101);

    return 0;
}
