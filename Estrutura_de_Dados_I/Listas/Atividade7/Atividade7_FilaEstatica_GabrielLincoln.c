#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5
typedef struct {
    int data[MAX_SIZE];
    int front, rear;
} Queue;
void initQueue(Queue *q) {
    q->front = q->rear = -1;
}
int isFull(Queue *q) {
    return (q->rear == MAX_SIZE - 1);
}
int isEmpty(Queue *q) {
    return (q->front == -1 || q->front > q->rear);
}
void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Erro: Fila cheia.\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->data[++q->rear] = value;
}
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Erro: Fila vazia.\n");
        return -1;
    }
    int value = q->data[q->front++];
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
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
    enqueue(&q, 60);
    return 0;
}