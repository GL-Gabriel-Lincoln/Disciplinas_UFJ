#include <stdio.h>
#define MAX 20

typedef struct {
    int data[MAX];
    int top;
} Stack;

void push(Stack *s, int item) {
    if (s->top == MAX - 1) {
        printf("A pilha está cheia!\n");
        return;
    }
    s->data[++(s->top)] = item;
}

int main() {
    Stack A, B;
    A.top = -1;
    B.top = -1;

    printf("Digite uma sequência de 20 números inteiros:\n");
    for (int i = 0; i < MAX; i++) {
        int num;
        scanf("%d", &num);
        if (num % 2 == 0) {
            push(&A, num);
        } else {
            push(&B, num);
        }
    }

    printf("Números pares na pilha A:\n");
    for (int i = 0; i <= A.top; i++) {
        printf("%d ", A.data[i]);
    }
    printf("\n");

    printf("Números ímpares na pilha B:\n");
    for (int i = 0; i <= B.top; i++) {
        printf("%d ", B.data[i]);
    }
    printf("\n");

    return 0;
}