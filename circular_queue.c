#include <stdio.h>
#define SIZE 5

// Structure to represent a circular queue
struct CircularQueue {
    int items[SIZE];
    int front;
    int rear;
};

// Function to check if the queue is full
int isFull(struct CircularQueue* queue) {
    if ((queue->rear + 1) % SIZE == queue->front)
        return 1;
    return 0;
}

// Function to check if the queue is empty
int isEmpty(struct CircularQueue* queue) {
    if (queue->front == -1)
        return 1;
    return 0;
}

// Function to add an element to the queue
void enqueue(struct CircularQueue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue element.\n");
    } else {
        if (queue->front == -1)
            queue->front = 0;
        queue->rear = (queue->rear + 1) % SIZE;
        queue->items[queue->rear] = value;
        printf("Enqueued element: %d\n", value);
    }
}

// Function to remove an element from the queue
int dequeue(struct CircularQueue* queue) {
    int element;
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue element.\n");
        return -1;
    } else {
        element = queue->items[queue->front];
        if (queue->front == queue->rear) {
            queue->front = -1;
            queue->rear = -1;
        } else {
            queue->front = (queue->front + 1) % SIZE;
        }
        return element;
    }
}

// Function to display the elements of the queue
void display(struct CircularQueue* queue) {
    int i;
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for (i = queue->front; i != queue->rear; i = (i + 1) % SIZE) {
            printf("%d ", queue->items[i]);
        }
        printf("%d\n", queue->items[i]);
    }
}

int main() {
    struct CircularQueue queue;
    queue.front = -1;
    queue.rear = -1;

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    enqueue(&queue, 4);
    enqueue(&queue, 5);

    display(&queue);

    int removedElement = dequeue(&queue);
    printf("Dequeued element: %d\n", removedElement);

    display(&queue);

    enqueue(&queue, 6);
    display(&queue);

    return 0;
}
