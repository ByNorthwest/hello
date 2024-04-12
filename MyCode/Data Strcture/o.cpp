#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int queue[MAX_SIZE];
    int rear;
    int length;
} CircularQueue;

CircularQueue* createCircularQueue() {
    CircularQueue* cq = (CircularQueue*)malloc(sizeof(CircularQueue));
    cq->rear = 0;
    cq->length = 0;
    return cq;
}

int isFull(CircularQueue* cq) {
    return cq->length == MAX_SIZE;
}

int isEmpty(CircularQueue* cq) {
    return cq->length == 0;
}

void enqueue(CircularQueue* cq, int item) {
    if (isFull(cq)) {
        return;
    }

    cq->queue[cq->rear] = item;
    cq->rear = (cq->rear + 1) % MAX_SIZE;
    cq->length++;
}

int dequeue(CircularQueue* cq) {
    if (isEmpty(cq)) {
        return -1;
    }
    int front_item = cq->queue[(cq->rear - cq->length + MAX_SIZE) % MAX_SIZE];
    cq->length--;
    return front_item;
}

void printQueue(CircularQueue* cq) {
    int i;
    printf("Queue: ");
    for (i = 0; i < cq->length; i++) {
        printf("%d ", cq->queue[(cq->rear - cq->length + i + MAX_SIZE) % MAX_SIZE]);
    }
    printf("\n");
}

int main() {
    int k, max, n;
    printf("Enter the value of k: ");
    scanf("%d", &k);

    printf("Enter the value of max: ");
    scanf("%d", &max);

    printf("Enter the value of n: ");
    scanf("%d", &n);

    CircularQueue* cq = createCircularQueue();

    // Initialize the queue with the first k Fibonacci numbers
    for (int i = 0; i < k; i++) {
        enqueue(cq, i);
    }

    // Generate and print Fibonacci numbers until f(n+1) > max
    int fib;
    for (int i = k; ; i++) {
        fib = 0;
        for (int j = 0; j < k; j++) {
            fib += cq  ->queue[(cq->rear - cq->length + j + MAX_SIZE) % MAX_SIZE];
        }
        if (fib > max) {
            break;
        }
        enqueue(cq, fib);
        dequeue(cq);
        printQueue(cq);
    }

    free(cq);
    return 0;
}
