#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct
{
    char data[MAX];
    int top;
} Stack;

void push(Stack *s, char item)
{
    if (s->top == MAX - 1)
    {
        printf("A pilha está cheia!\n");
        return;
    }
    s->data[++(s->top)] = item;
}

char pop(Stack *s)
{
    if (s->top == -1)
    {
        printf("A pilha está vazia!\n");
        return '\0';
    }
    return s->data[(s->top)--];
}

int main()
{
    char str[MAX];
    printf("Digite uma string: ");
    fgets(str, MAX, stdin);

    str[strcspn(str, "\n")] = 0;

    Stack s;
    s.top = -1;

    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        push(&s, str[i]);
    }

    for (int i = 0; i < len; i++)
    {
        if (str[i] != pop(&s))
        {
            printf("A string não é um palíndromo.\n");
            return 0;
        }
    }

    printf("A string é um palíndromo.\n");
    return 0;
}