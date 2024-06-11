#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* criarNo(int valor) {
    struct Node* novoNo = (struct Node*)malloc(sizeof(struct Node));
    novoNo->data = valor;
    novoNo->prev = NULL;
    novoNo->next = NULL;
    return novoNo;
}

void inserirNoMeio(struct Node** head, int valor) {
    struct Node* novoNo = criarNo(valor);

    if (*head == NULL) {
        *head = novoNo;
        return;
    }

    struct Node* atual = *head;
    int tamanho = 0;
    while (atual != NULL) {
        tamanho++;
        atual = atual->next;
    }

    int meio = tamanho / 2;
    atual = *head;
    for (int i = 0; i < meio; i++) {
        atual = atual->next;
    }

    novoNo->prev = atual;
    novoNo->next = atual->next;
    if (atual->next != NULL) {
        atual->next->prev = novoNo;
    }
    atual->next = novoNo;
}

void imprimirLista(struct Node* head) {
    struct Node* atual = head;
    while (atual != NULL) {
        printf("%d ", atual->data);
        atual = atual->next;
    }
    printf("\n");
}

int main() {
    struct Node* lista = NULL;
    inserirNoMeio(&lista, 10);
    inserirNoMeio(&lista, 20);
    inserirNoMeio(&lista, 30);

    printf("Lista após inserção no meio: ");
    imprimirLista(lista);

    return 0;
}
