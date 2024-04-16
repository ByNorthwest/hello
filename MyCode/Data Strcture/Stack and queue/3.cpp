#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int *data;
    int rear;
    int front;
    int tag;
} SeqQueue;

void initial(SeqQueue *que, int k) {
    que->rear = que->front = 0;
    que->tag = 0;
    que->data = (int *)malloc(sizeof(int) * (k + 1)); // 加1是为了避免队列满时无法区分空和满的情况
    if (que->data == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
}

void enQueue(SeqQueue *que, int a, int k) {
    if ((que->rear + 1) % (k + 1) == que->front) { // 队列满
        printf("Queue is full\n");
        exit(EXIT_FAILURE);
    }

    que->data[que->rear] = a;
    que->rear = (que->rear + 1) % (k + 1);
    que->tag = 0;
}

void deQueue(SeqQueue *que, int *p, int k) {
    if (que->front == que->rear) { // 队列空
        printf("Queue is empty\n");
        exit(EXIT_FAILURE);
    }

    *p = que->data[que->front];
    que->front = (que->front + 1) % (k + 1);
    que->tag = 0;
}

void Fibonaci(int max, int k) {
    SeqQueue que;
    initial(&que, k);
    
    for (int i = 0; i < k; i++) {
        enQueue(&que, 0, k);
    }
    
    enQueue(&que, 1, k);
    enQueue(&que, 1, k);
    
    int a = 1, b = 1, c = 2;
    while (c <= max) {
        enQueue(&que, c, k);
        a = b;
        b = c;
        c = a + b;
    }
    
    int h;
    for (int i = 0; i < k; i++) {
        deQueue(&que, &h, k);
        printf("%d ", h);
    }
    printf("\n");
    free(que.data); // 释放动态分配的内存
}

int main() {
    int max, k;
    printf("Enter the maximum value (max) and the queue size (k): ");
    scanf("%d %d", &max, &k);
    Fibonaci(max, k);
    return 0;
}
