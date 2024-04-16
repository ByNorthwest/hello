#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int row,col,num;
    struct Node *down,*right;
}Node,*LNode ;
typedef struct {
    LNode * row_head,*col_head;//col_head之前也必须有*
    int m,n,len;
}CrossList;

void createCross(CrossList * A,int m,int n,int num){
    A->m = m;
    A->n = n;
    A->row_head = (LNode *)malloc((m+1)*sizeof(LNode));
    A->col_head = (LNode *)malloc((n +1)*sizeof(LNode));
    for(int i=0;i<=m;i++){
        A->row_head[i] = NULL;
    }
    for(int i=0;i<=n;i++)
        A->col_head [i] =NULL;
    for(int i = 1;i<=num;i++){
        int k,j,e;
        scanf("%d%d%d",&k,&j,&e);
        LNode p = (LNode)malloc(sizeof(Node));
        p ->row = k;
        p->col = j;
        p->num = e;
        if (A->row_head[i]==NULL){
            A->row_head[i] = p;
            p->right =NULL;}
        else{
            LNode q = A->row_head[i];
            while(q->right !=NULL){
                q = q->right;

            }
            p ->right = q->right;
            q->right=p;
        }
    
    }
}
void calculateCross(CrossList * A, CrossList B){
    for(int i = 1; i <= A->m; i++){
        LNode pa = A->row_head[i];
        LNode pb = B.row_head[i];
        while(pa != NULL && pb != NULL){  // 检查 pa 和 pb 是否为空
            if(pa->col == pb->col){
                pa->num += pb->num;
                pa = pa->right;
                pb = pb->right;
            } else if(pa->col < pb->col){
                pa = pa->right;
            } else {
                LNode newnode = (LNode)malloc(sizeof(Node));
                newnode->col = pb->col;
                newnode->num = pb->num;
                newnode->row = i;
                newnode->down = NULL;
                if(newnode->col < A->row_head[i]->col){
                    newnode->right = A->row_head[i];
                    A->row_head[i] = newnode;
                } else {
                    newnode->right = pa;
                    pa = newnode;  // 更新 pa 为新节点，而不是 pa->right
                }
                pb = pb->right;
            }
        }
    }
}

void outputCross(CrossList A){
    for(int i = 1; i <= A.m; i++){
        LNode temp = A.row_head[i];  // 使用临时变量来遍历链表，而不是直接修改 A.row_head[i]
        while(temp != NULL){
            printf("%d %d %d\n", temp->row, temp->col, temp->num);
            temp = temp->right;
        }
    }
}

void master(){
    CrossList A,B;
    int m,n,num1,num2;
    scanf("%d%d%d%d",&m,&n,&num1,&num2);
    createCross(&A,m,n,num1);
    createCross(&B,m,n,num2);
    calculateCross(&A,B);
    outputCross(A);

}
int main(){
    master();
    return 0;
}