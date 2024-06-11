#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int valor;
    struct Node* proximo;
} Node;

Node* criarNo(int numero) {
    Node* novoNo = (Node*)malloc(sizeof(Node));
    if (novoNo == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    novoNo->valor = numero;
    novoNo->proximo = NULL;
    return novoNo;
}

void inserirInicio(Node** cabeca, int numero) {
    Node* novoNo = criarNo(numero);
    novoNo->proximo = *cabeca;
    *cabeca = novoNo;
}

void deletarNo(Node** cabeca, int chave) {
    Node* aux = *cabeca;
    Node* anterior = NULL;

    if (aux != NULL && aux->valor == chave) {
        *cabeca = aux->proximo;
        free(aux);
        return;
    }
    while (aux != NULL && aux->valor != chave) {
        anterior = aux;
        aux = aux->proximo;
    }
    if (aux == NULL) {
        printf("Valor não encontrado na lista.\n");
        return;
    }
    anterior->proximo = aux->proximo;
    free(aux);
}

void inserirFim(Node** cabeca, int numero) {
    Node* novoNo = criarNo(numero);
    if (*cabeca == NULL) {
        *cabeca = novoNo;
        return;
    }
    Node* aux = *cabeca;
    while (aux->proximo != NULL) {
        aux = aux->proximo;
    }
    aux->proximo = novoNo;
}

void removerInicio(Node** cabeca) {
    if (*cabeca == NULL) {
        printf("A lista já está vazia.\n");
        return;
    }
    Node* aux = *cabeca;
    *cabeca = aux->proximo;
    free(aux);
}

void removerFim(Node** cabeca) {
    if (*cabeca == NULL) {
        printf("A lista já está vazia.\n");
        return;
    }
    if ((*cabeca)->proximo == NULL) {
        free(*cabeca);
        *cabeca = NULL;
        return;
    }
    Node* aux = *cabeca;
    Node* anterior = NULL;
    while (aux->proximo != NULL) {
        anterior = aux;
        aux = aux->proximo;
    }
    anterior->proximo = NULL;
    free(aux);
}

void exibir(Node* cabeca) {
    Node* aux = cabeca;
    while (aux != NULL) {
        printf("[%d] -> ", aux->valor);
        aux = aux->proximo;
    }
    printf("NULL\n");
}

int main() {
    Node* cabeca = NULL;

    inserirInicio(&cabeca, 10);
    inserirFim(&cabeca, 20);
    inserirInicio(&cabeca, 5);
    inserirFim(&cabeca, 30);

    printf("Lista: ");
    exibir(cabeca);

    removerInicio(&cabeca);
    printf("Após remover do início: ");
    exibir(cabeca);

    removerFim(&cabeca);
    printf("Após remover do fim: ");
    exibir(cabeca);

    return 0;
}
