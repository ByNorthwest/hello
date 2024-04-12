#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

typedef struct {
    int data[MAXSIZE];
    int rear;
    int front;
} SeqQueue;

void initial(SeqQueue* que) {
    que->rear = que->front = 0;
}

void enQueue(SeqQueue* que, int a) {
    que->data[que->rear] = a;
    que->rear = (que->rear + 1) % MAXSIZE;
}

void deQueue(SeqQueue* que, int* p) {
    *p = que->data[que->front];
    que->front = (que->front + 1) % MAXSIZE;
}

void kFibonacci(int n, int k, int max) {
    SeqQueue que;
    initial(&que);

    // 初始化队列
    for (int i = 0; i < k; i++) {
        enQueue(&que, 0);
    }
    enQueue(&que, 1);

    int fib[k];
    for (int i = 0; i < k; i++) {
        fib[i] = 0;
    }
    fib[k - 1] = 1;

    // 生成斐波那契数列
    int i = 0;
    while (fib[i % k] <= max) {
        int next_fib = 0;
        for (int j = 0; j < k; j++) {
            next_fib += fib[j];
        }
        next_fib = next_fib - fib[i % k];

        if (next_fib > max) {
            break;
        }

        enQueue(&que, next_fib);
        deQueue(&que, &fib[i % k]);
        fib[(i + k) % k] = next_fib;
        i++;
    }

    // 输出结果
    while (que.front != que.rear) {
        int temp;
        deQueue(&que, &temp);
        printf("%d ", temp);
    }
    printf("\n");
}

int main() {
    int n, k, max;
    scanf("%d %d %d", &n, &k, &max);
    kFibonacci(n, k, max);
    return 0;
}
