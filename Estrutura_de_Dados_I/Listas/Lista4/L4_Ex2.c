#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person
{
    char name[50];
    int age;
    struct Person *next;
} Person;

Person *createPerson(char *name, int age)
{
    Person *p = (Person *)malloc(sizeof(Person));
    strcpy(p->name, name);
    p->age = age;
    p->next = NULL;
    return p;
}

void push(Person **top, char *name, int age)
{
    Person *newPerson = createPerson(name, age);
    newPerson->next = *top;
    *top = newPerson;
}

void pop(Person **top, char *name)
{
    Person *temp = *top;
    Person *prev = NULL;

    if (temp != NULL && strcmp(temp->name, name) == 0)
    {
        *top = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && strcmp(temp->name, name) != 0)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;
    free(temp);
}

void printStack(Person *top)
{
    while (top != NULL)
    {
        printf("%s, %d\n", top->name, top->age);
        top = top->next;
    }
}

int main()
{
    Person *top = NULL;

    push(&top, "João", 20);
    push(&top, "Maria", 25);
    push(&top, "Pedro", 30);

    printf("Pilha original:\n");
    printStack(top);

    pop(&top, "Maria");

    printf("\nPilha após remover 'Maria':\n");
    printStack(top);

    return 0;
}
