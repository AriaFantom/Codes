#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

/**
 * Initializes the queue by setting the front and rear indices to -1.
 * 
 * @param q Pointer to the queue to be initialized.
 */
void init(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

/**
 * Checks if the queue is empty.
 * 
 * @param q Pointer to the queue to be checked.
 * @return 1 if the queue is empty, 0 otherwise.
 */
int is_empty(Queue *q) {
    return q->front == -1;
}

/**
 * Checks if the queue is full.
 * 
 * @param q Pointer to the queue to be checked.
 * @return 1 if the queue is full, 0 otherwise.
 */
int is_full(Queue *q) {
    return q->rear == MAX_SIZE - 1;
}

/**
 * Adds an element to the rear of the queue.
 * 
 * @param q Pointer to the queue to which the element is to be added.
 * @param value The value to be added to the queue.
 */
void enqueue(Queue *q, int value) {
    if (is_full(q)) {
        printf("Queue is full\n");
        return;
    }
    if (is_empty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->data[q->rear] = value;
}

/**
 * Removes and returns the element at the front of the queue.
 * 
 * @param q Pointer to the queue from which the element is to be removed.
 * @return The value of the element removed from the queue, or -1 if the queue is empty.
 */
int dequeue(Queue *q) {
    if (is_empty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int value = q->data[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    return value;
}

/**
 * The main function initializes a queue, adds three elements to it, and then removes and prints them in FIFO order.
 */
int main() {
    Queue q;
    init(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));
    return 0;
}
