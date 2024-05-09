#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack
{
    int top;
    unsigned capacity;
    char *array;
} Stack;

Stack *createStack(unsigned capacity)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char *)malloc(stack->capacity * sizeof(char));
    return stack;
}

void push(Stack *stack, char item)
{
    stack->array[++stack->top] = item;
}

char pop(Stack *stack)
{
    return stack->array[stack->top--];
}

char peek(Stack *stack)
{
    return stack->array[stack->top];
}

int isStackEmpty(Stack *stack)
{
    return stack->top == -1;
}

int checkStringFormat(char *str)
{
    int len = strlen(str);
    Stack *stack = createStack(len);

    int i;
    for (i = 0; i < len; i++)
    {
        if (str[i] == 'c')
        {
            break;
        }
        push(stack, str[i]);
    }

    if (i == len || i == len - 1)
    {
        return 0;
    }

    i++;
    while (!isStackEmpty(stack))
    {
        if (str[i++] != pop(stack))
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    char str[] = "ababcbaba";
    if (checkStringFormat(str))
    {
        printf("A string pertence ao formato.\n");
    }
    else
    {
        printf("A string não pertence ao formato.\n");
    }
    return 0;
}