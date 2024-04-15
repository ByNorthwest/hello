#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 1000
typedef struct {
    int num;
    int col;
    int row;
}Triple;
typedef struct {
    Triple data[MAXSIZE];
    int len;
    int n;
    int m;
}TSMatrix;
void initialTSM(TSMatrix *A,int m,int n){
    A->len = 0;
    A->m = m;
    A->n = n;
}
void appendTSM(TSMatrix *A,int row,int col,int num){
    A->len ++;
    A->data[A->len ].col = col;
    A->data[A->len].row = row;
    A->data[A->len].num = num;
}
void moveforward(TSMatrix *A,int now){
    A->len ++;
    int i = A->len;
    for(;i>now;i--){
        A->data[i].col = A->data[i-1].col;
        A->data[i].num = A->data[i-1].num;
        A->data[i].row = A->data[i-1].row;
    }
}
void calculateTSM(TSMatrix *A,TSMatrix B){
    int p = 1,i=1;//双指针法
    for(;i<=A->len && p <= B.len;){
        if(A->data[i].row  == B.data[p].row){
            if(A->data[i].col == B.data[p].col){
                A->data[i].num+=B.data[p].num;
                i++;
                p++;
            }else if(A->data[i].col > B.data[p].col){
                moveforward(A,i);
                A->data[i].col = B.data[p].col;
                A->data[i].num = B.data[p].num;
                p++;
                continue;
            }else{
                i++;
                continue;
            }
        }else if(A->data[i].row > B.data[p].row){
            moveforward(A,i);
            A->data[i].row = B.data[p].row;
            A->data[i].col = B.data[p].col;
            A->data[i].num = B.data[p].num;
            p++;
            continue;
        }else{
            i++;
            continue;
        }
    }
}
void outputTSM(TSMatrix A){
    int i;
    for(i=1;i<=A.len;i++){
        if (A.data[i].row == 0&&A.data[i].col == 0&&A.data[i].num ==0){
            break;
        }
        printf("%d %d %d\n",A.data[i].row,A.data[i].col,A.data[i].num);

    }
   
}
void master(){
    TSMatrix A,B;
    int m,n,num1,num2;
    scanf("%d%d%d%d",&m,&n,&num1,&num2);
    initialTSM(&B,m,n);
    initialTSM(&A,m,n);
    for(int i = 0;i<num1;i++){
        int row,col,num;
        scanf("%d%d%d",&row,&col,&num);
        appendTSM(&A,row,col,num);
    }
    for(int i=0;i<num2;i++){
        int row,col,num;
        scanf("%d%d%d",&row,&col,&num);
        appendTSM(&B,row,col,num);
    }
    calculateTSM(&A,B);

    outputTSM(A);
}
int main(){
    master();
    return 0;
}