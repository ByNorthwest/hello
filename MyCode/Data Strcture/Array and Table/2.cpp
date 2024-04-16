
#include <stdio.h>

#define MAX_SIZE 10

typedef struct {
    int data[MAX_SIZE];
    int rear;
    int length;
} CircularQueue;

void initQueue(CircularQueue *queue) {
    queue->rear = -1;
    queue->length = 0;
}

int isFull(CircularQueue *queue) {
    return queue->length == MAX_SIZE;
}

int isEmpty(CircularQueue *queue) {
    return queue->length == 0;
}

void enqueue(CircularQueue *queue, int item) {
    if (!isFull(queue)) {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
        queue->data[queue->rear] = item;
        queue->length++;
    } else {
        printf("yes\n");
    }
}

int dequeue(CircularQueue *queue) {
    if (!isEmpty(queue)) {
        int front = queue->data[(queue->rear - queue->length + 1 + MAX_SIZE) % MAX_SIZE];
        queue->length--;
        return front;
    } else {
        return -1;
    }
}

void printQueue(CircularQueue *queue) {
    printf("Current queue: ");
    if (isEmpty(queue)) {
        printf("Empty\n");
        return;
    }
    int index = queue->rear;
    for (int i = 0; i < queue->length; i++) {
        printf("%d ", queue->data[(index - i + MAX_SIZE) % MAX_SIZE]);
    }
    printf("\n");
}

int main() {
    CircularQueue queue;
    initQueue(&queue);

    int N, item;
    scanf("%d", &N);
    printf("Input enqueue elements:\n");
    for (int i = 0; i < N; i++) {
        scanf("%d", &item);
        enqueue(&queue, item);
        printf("Is queue full? ");
        if (isFull(&queue)) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }

    printf("Input dequeue element:\n");
    scanf("%d", &item);
    int front = dequeue(&queue);
    if (front != -1) {
        printf("Dequeued element: %d\n", front);
    } else {
        printf("Queue is empty\n");
    }
    printQueue(&queue);

    return 0;
}
