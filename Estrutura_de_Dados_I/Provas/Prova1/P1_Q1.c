/*1) Escreva um programa que receba do usuário o nome e a idade de uma pessoa. Armazene as informações em duas pilhas, da escolha do usuário.
Escreva um programa que transfira os elementos dessas pilhas para uma terceira pilha, inicialmente vazia, de modo que ela fique ordenada em
ordem decrescente de idade, ou seja, com a pessoa mais velha no topo. O seu programa precisa apresentar para o usuário, pelo menos, as seguintes opções:
• Inserir valores na pilha 1;
• Inserir valores na pilha 2;
• Exibir a pilha 3.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[50];
    int age;
} Person;

typedef struct node
{
    Person p;
    struct node *next;
} Node;

typedef struct
{
    Node *top;
} Stack;

Stack *createStack()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

void push(Stack *s, Person person)
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->p = person;
    n->next = s->top;
    s->top = n;
}

Person pop(Stack *s)
{
    if (s->top == NULL)
    {
        printf("Pilha vazia.\n");
        Person person;
        strcpy(person.name, "");
        person.age = -1;
        return person;
    }

    Node *n = s->top;
    Person person = n->p;
    s->top = n->next;
    free(n);
    return person;
}

void insertOrdered(Stack *s, Person person)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->p = person;
    newNode->next = NULL;

    if (s->top == NULL || s->top->p.age <= person.age)
    {
        newNode->next = s->top;
        s->top = newNode;
    }
    else
    {
        Node *current = s->top;
        while (current->next != NULL && current->next->p.age > person.age)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void fillStack3(Stack *s1, Stack *s2, Stack *s3)
{
    while (s1->top != NULL || s2->top != NULL)
    {
        Person person1, person2;
        if (s1->top != NULL)
        {
            person1 = s1->top->p;
        }
        else
        {
            person1.age = -1;
        }
        if (s2->top != NULL)
        {
            person2 = s2->top->p;
        }
        else
        {
            person2.age = -1;
        }
        if (person1.age >= person2.age)
        {
            insertOrdered(s3, pop(s1));
        }
        else
        {
            insertOrdered(s3, pop(s2));
        }
    }
}

int main()
{
    Stack *s1 = createStack();
    Stack *s2 = createStack();
    Stack *s3 = createStack();

    while (1)
    {
        printf("1. Inserir valores na pilha 1\n");
        printf("2. Inserir valores na pilha 2\n");
        printf("3. Exibir a pilha 3\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        int option;
        scanf("%d", &option);

        if (option == 1 || option == 2)
        {
            printf("Digite o nome: ");
            Person person;
            scanf("%s", person.name);
            printf("Digite a idade: ");
            scanf("%d", &person.age);
            if (option == 1)
            {
                push(s1, person);
            }
            else
            {
                push(s2, person);
            }
        }
        else if (option == 3)
        {
            if (s1->top == NULL && s2->top == NULL)
            {
                printf("Por favor, insira valores nas pilhas 1 e 2 primeiro.\n");
                continue;
            }
            fillStack3(s1, s2, s3);

            Node *n = s3->top;
            while (n != NULL)
            {
                printf("Nome: %s, Idade: %d\n", n->p.name, n->p.age);
                n = n->next;
            }
        }

        else if (option == 4)
        {
            break;
        }
        else
        {
            printf("Opção inválida.\n");
        }
    }

    return 0;
}