#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *front, *rear;
} Queue;
void initQueue(Queue *q) {
    q->front = q->rear = NULL;
}
int isEmpty(Queue *q) {
    return (q->front == NULL);
}
void enqueue(Queue *q, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (isEmpty(q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Erro: Fila vazia.\n");
        return -1;
    }
    int value = q->front->data;
    Node *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return value;
}
int main() {
    Queue q;
    initQueue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    printf("Elemento removido: %d\n", dequeue(&q));
    enqueue(&q, 40);
    enqueue(&q, 50);
    printf("Elemento removido: %d\n", dequeue(&q));
    return 0;
}