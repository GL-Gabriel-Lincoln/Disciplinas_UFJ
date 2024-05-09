/*2) Crie a função intercalaPilha(pilha p1, pilha p2) que deve testar se duas pilhas possuem o mesmo tamanho e 
em caso afirmativo intercalar os elementos da pilha 1 com a pilha 2 e armazenar em uma pilha 3. 
As pilhas devem armazenar valores do tipo caracter.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    char data;
    struct Stack* next;
} Stack;

Stack* createStack() {
    return NULL;
}

Stack* push(Stack* s, char v) {
    Stack* new = (Stack*) malloc(sizeof(Stack));
    new->data = v;
    new->next = s;
    return new;
}

char pop(Stack** s) {
    Stack* t;
    char v;
    if(*s == NULL) {
        printf("Pilha vazia.\n");
        exit(1);
    }
    t = *s;
    v = t->data;
    *s = t->next;
    free(t);
    return v;
}

int isEmpty(Stack* s) {
    return (s == NULL);
}

int stackSize(Stack* s) {
    Stack* c;
    int i = 0;
    for(c = s; c != NULL; c = c->next) {
        i++;
    }
    return i;
}

Stack* interleaveStack(Stack* s1, Stack* s2) {
    if(stackSize(s1) != stackSize(s2)) {
        printf("As pilhas não possuem o mesmo tamanho.\n");
        return NULL;
    }
    Stack* s3 = createStack();
    while(!isEmpty(s1)) {
        s3 = push(s3, pop(&s1));
        s3 = push(s3, pop(&s2));
    }
    return s3;
}

void insertElements(Stack** s) {
    int n;
    char c;
    printf("Quantos elementos você deseja inserir na pilha? ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        printf("Insira o elemento %d: ", i+1);
        scanf(" %c", &c);
        *s = push(*s, c);
    }
}

int main() {
    Stack* s1 = createStack();
    Stack* s2 = createStack();

    printf("Inserindo elementos na pilha p1...\n");
    insertElements(&s1);

    printf("Inserindo elementos na pilha p2...\n");
    insertElements(&s2);

    Stack* s3 = interleaveStack(s1, s2);

    if(s3 != NULL) {
        printf("Elementos da pilha intercalada:\n");
        while(!isEmpty(s3)) {
            printf("%c\n", pop(&s3));
        }
    }

    return 0;
}