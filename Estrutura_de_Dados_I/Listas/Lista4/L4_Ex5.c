#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct
{
    int items[MAX_SIZE];
    int top;
} Stack;

void push(Stack *ps, int x)
{
    if (ps->top == MAX_SIZE - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    ps->top++;
    ps->items[ps->top] = x;
}

int pop(Stack *ps)
{
    if (ps->top == -1)
    {
        printf("Stack underflow\n");
        exit(1);
    }
    int temp = ps->items[ps->top];
    ps->top--;
    return temp;
}

int size(Stack *ps)
{
    return ps->top + 1;
}

Stack *intercalaPilha(Stack *p1, Stack *p2)
{
    if (size(p1) != size(p2))
    {
        printf("As pilhas não têm o mesmo tamanho\n");
        return NULL;
    }

    Stack *p3 = (Stack *)malloc(sizeof(Stack));
    p3->top = -1;

    while (size(p1) > 0 && size(p2) > 0)
    {
        push(p3, pop(p1));
        push(p3, pop(p2));
    }

    return p3;
}

int main()
{
    Stack *p1 = (Stack *)malloc(sizeof(Stack));
    p1->top = -1;
    Stack *p2 = (Stack *)malloc(sizeof(Stack));
    p2->top = -1;

    for (int i = 0; i < 5; i++)
    {
        push(p1, i);
        push(p2, i + 5);
    }

    Stack *p3 = intercalaPilha(p1, p2);

    if (p3 != NULL)
    {
        printf("Elementos da pilha intercalada:\n");
        while (size(p3) > 0)
        {
            printf("%d ", pop(p3));
        }
        printf("\n");
    }

    free(p1);
    free(p2);
    free(p3);

    return 0;
}
