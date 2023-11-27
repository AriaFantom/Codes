#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} Dequeue;

void initialize(Dequeue *dq) {
    dq->front = -1;
    dq->rear = -1;
}

/**
 * Checks if the dequeue is full.
 * 
 * @param dq The dequeue to be checked.
 * @return 1 if the dequeue is full, 0 otherwise.
 */
int isFull(Dequeue *dq) {
    return (dq->front == 0 && dq->rear == MAX_SIZE - 1) || (dq->front == dq->rear + 1);
}

int isEmpty(Dequeue *dq) {
    return dq->front == -1;
}

void insertFront(Dequeue *dq, int item) {
    if (isFull(dq)) {
        printf("Dequeue is full. Cannot insert.\n");
        return;
    }

    if (dq->front == -1) {
        dq->front = 0;
        dq->rear = 0;
    } else if (dq->front == 0) {
        dq->front = MAX_SIZE - 1;
    } else {
        dq->front--;
    }

    dq->data[dq->front] = item;
    printf("Inserted %d at the front.\n", item);
}

void insertRear(Dequeue *dq, int item) {
    if (isFull(dq)) {
        printf("Dequeue is full. Cannot insert.\n");
        return;
    }

    if (dq->front == -1) {
        dq->front = 0;
        dq->rear = 0;
    } else if (dq->rear == MAX_SIZE - 1) {
        dq->rear = 0;
    } else {
        dq->rear++;
    }

    dq->data[dq->rear] = item;
    printf("Inserted %d at the rear.\n", item);
}

int deleteFront(Dequeue *dq) {
    if (isEmpty(dq)) {
        printf("Dequeue is empty. Cannot delete.\n");
        return -1;
    }

    int item = dq->data[dq->front];

    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else if (dq->front == MAX_SIZE - 1) {
        dq->front = 0;
    } else {
        dq->front++;
    }

    printf("Deleted %d from the front.\n", item);
    return item;
}

int deleteRear(Dequeue *dq) {
    if (isEmpty(dq)) {
        printf("Dequeue is empty. Cannot delete.\n");
        return -1;
    }

    int item = dq->data[dq->rear];

    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else if (dq->rear == 0) {
        dq->rear = MAX_SIZE - 1;
    } else {
        dq->rear--;
    }

    printf("Deleted %d from the rear.\n", item);
    return item;
}

void display(Dequeue *dq) {
    if (isEmpty(dq)) {
        printf("Dequeue is empty.\n");
        return;
    }

    printf("Dequeue elements: ");
    int i = dq->front;
    while (i != dq->rear) {
        printf("%d ", dq->data[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", dq->data[i]);
}

int main() {
    Dequeue dq;
    initialize(&dq);

    insertFront(&dq, 10);
    insertFront(&dq, 20);
    insertRear(&dq, 30);
    insertRear(&dq, 40);

    display(&dq);

    deleteFront(&dq);
    deleteRear(&dq);

    display(&dq);

    return 0;
}
