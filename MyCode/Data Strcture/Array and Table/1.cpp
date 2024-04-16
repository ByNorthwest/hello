#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int row, col, num;
    struct Node *down, *right;
} Node, *LNode;

typedef struct {
    LNode *row_head, *col_head;
    int m, n;
} CrossList;

void createCross(CrossList *A, int m, int n, int num) {
    A->m = m;
    A->n = n;
    A->row_head = (LNode *)malloc((m + 1) * sizeof(LNode));
    A->col_head = (LNode *)malloc((n + 1) * sizeof(LNode));
    for (int i = 0; i <= m; i++) {
        A->row_head[i] = NULL;
    }
    for (int i = 0; i <= n; i++) {
        A->col_head[i] = NULL;
    }
    for (int i = 1; i <= num; i++) {
        int k, j, e;
        scanf("%d%d%d", &k, &j, &e);
        LNode p = (LNode)malloc(sizeof(Node));
        p->row = k;
        p->col = j;
        p->num = e;
        p->right = NULL;
        p->down = NULL;
        if (A->row_head[k] == NULL) {
            A->row_head[k] = p;
        }
        else {
            LNode q = A->row_head[k];
            while (q->right != NULL) {
                q = q->right;
            }
            q->right = p;
        }
        if (A->col_head[j] == NULL) {
            A->col_head[j] = p;
        }
        else {
            LNode q = A->col_head[j];
            while (q->down != NULL) {
                q = q->down;
            }
            q->down = p;
        }
    }
}

void addCross(CrossList A, CrossList B, CrossList *C) {
    if (A.m != B.m || A.n != B.n) {
        printf("Matrices have different dimensions\n");
        return;
    }
    C->m = A.m;
    C->n = A.n;
    C->row_head = (LNode *)malloc((C->m + 1) * sizeof(LNode));
    C->col_head = (LNode *)malloc((C->n + 1) * sizeof(LNode));
    for (int i = 0; i <= C->m; i++) {
        C->row_head[i] = NULL;
    }
    for (int i = 0; i <= C->n; i++) {
        C->col_head[i] = NULL;
    }
    for (int i = 1; i <= A.m; i++) {
        LNode pa = A.row_head[i];
        LNode pb = B.row_head[i];
        LNode pc = NULL;
        LNode pre = NULL;
        while (pa != NULL && pb != NULL) {
            LNode p = (LNode)malloc(sizeof(Node));
            if (pa->col < pb->col) {
                p->row = pa->row;
                p->col = pa->col;
                p->num = pa->num;
                pa = pa->right;
            }
            else if (pa->col > pb->col) {
                p->row = pb->row;
                p->col = pb->col;
                p->num = pb->num;
                pb = pb->right;
            }
            else {
                p->row = pa->row;
                p->col = pa->col;
                p->num = pa->num + pb->num;
                pa = pa->right;
                pb = pb->right;
            }
            p->right = NULL;
            p->down = NULL;
            if (C->row_head[p->row] == NULL || C->row_head[p->row]->col > p->col) {
                p->right = C->row_head[p->row];
                C->row_head[p->row] = p;
            }
            else {
                pc = C->row_head[p->row];
                while (pc != NULL && pc->col < p->col) {
                    pre = pc;
                    pc = pc->right;
                }
                if (pc == NULL) {
                    pre->right = p;
                }
                else if (pc->col == p->col) {
                    pc->num += p->num;
                    free(p);
                }
                else {
                    pre->right = p;
                    p->right = pc;
                }
            }
            if (C->col_head[p->col] == NULL || C->col_head[p->col]->row > p->row) {
                p->down = C->col_head[p->col];
                C->col_head[p->col] = p;
            }
            else {
                pc = C->col_head[p->col];
                while (pc != NULL && pc->row < p->row) {
                    pre = pc;
                    pc = pc->down;
                }
                if (pc == NULL) {
                    pre->down = p;
                }
                else {
                    pre->down = p;
                    p->down = pc;
                }
            }
        }
        while (pa != NULL) {
            LNode p = (LNode)malloc(sizeof(Node));
            p->row = pa->row;
            p->col = pa->col;
            p->num = pa->num;
            p->right = NULL;
            p->down = NULL;
            if (C->row_head[p->row] == NULL || C->row_head[p->row]->col > p->col) {
                p->right = C->row_head[p->row];
                C->row_head[p->row] = p;
            }
            else {
                pc = C->row_head[p->row];
                while (pc != NULL && pc->col < p->col) {
                    pre = pc;
                    pc = pc->right;
                }
                if (pc == NULL) {
                    pre->right = p;
                }
                else if (pc->col == p->col) {
                    pc->num += p->num;
                    free(p);
                }
                else {
                    pre->right = p;
                    p->right = pc;
                }
            }
            if (C->col_head[p->col] == NULL || C->col_head[p->col]->row > p->row) {
                p->down = C->col_head[p->col];
                C->col_head[p->col] = p;
            }
            else {
                pc = C->col_head[p->col];
                while (pc != NULL && pc->row < p->row) {
                    pre = pc;
                    pc = pc->down;
                }
                if (pc == NULL) {
                    pre->down = p;
                }
                else {
                    pre->down = p;
                    p->down = pc;
                }
            }
            pa = pa->right;
        }
        while (pb != NULL) {
            LNode p = (LNode)malloc(sizeof(Node));
            p->row = pb->row;
            p->col = pb->col;
            p->num = pb->num;
            p->right = NULL;
            p->down = NULL;
            if (C->row_head[p->row] == NULL || C->row_head[p->row]->col > p->col) {
                p->right = C->row_head[p->row];
                C->row_head[p->row] = p;
            }
            else {
                pc = C->row_head[p->row];
                while (pc != NULL && pc->col < p->col) {
                    pre = pc;
                    pc = pc->right;
                }
                if (pc == NULL) {
                    pre->right = p;
                }
                else if (pc->col == p->col) {
                    pc->num += p->num;
                    free(p);
                }
                else {
                    pre->right = p;
                    p->right = pc;
                }
            }
            if (C->col_head[p->col] == NULL || C->col_head[p->col]->row > p->row) {
                p->down = C->col_head[p->col];
                C->col_head[p->col] = p;
            }
            else {
                pc = C->col_head[p->col];
                while (pc != NULL && pc->row < p->row) {
                    pre = pc;
                    pc = pc->down;
                }
                if (pc == NULL) {
                    pre->down = p;
                }
                else {
                    pre->down = p;
                    p->down = pc;
                }
            }
            pb = pb->right;
        }
    }
}

void outputCross(CrossList A) {
    for (int i = 1; i <= A.m; i++) {
        LNode p = A.row_head[i];
        while (p != NULL) {
            printf("%d %d %d\n", p->row, p->col, p->num);
            p = p->right;
        }
    }
}

void freeCross(CrossList *A) {
    for (int i = 0; i <= A->m; i++) {
        LNode p = A->row_head[i];
        while (p != NULL) {
            LNode temp = p;
            p = p->right;
            free(temp);
        }
    }
    free(A->row_head);
    free(A->col_head);
}

int main() {
    CrossList A, B, C;
    int m, n, num1, num2;
    scanf("%d%d%d%d", &m, &n, &num1,&num2);
    createCross(&A, m, n, num1);
    
    createCross(&B, m, n, num2);
    addCross(A, B, &C);
    outputCross(C);
    freeCross(&A);
    freeCross(&B);
    freeCross(&C);
    return 0;
}
