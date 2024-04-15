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
TSMatrix calculateTSM(TSMatrix A,TSMatrix B){
    int i = 1 ,p = 1,sum=0;
    TSMatrix C;
    initialTSM(&C,A.m,B.n);
    for(;i<= A.m ;i++){
        p = 1;
        for(;p <= B.n;p++){
            sum = 0;
            for(int j = 1,k = 1;j<=A.n ;j++,k++){
               for(int m = 1;m<=A.len;m++){
                    for(int o =1 ;o<=B.len;o++){
                        if ( B.data[o].col == p    &&A.data[m].row == i &&A.data[m].col == j && B.data[o].row == k){
                            sum += A.data[m].num * B.data[o].num;//此处为o，手误打成o，调试出来
                        }
                    }
               }
            }
            appendTSM(&C,i,p,sum);
        }
    }    
    return C;
}

void outputTSM(TSMatrix A){
    int i;
    for(i=1;i<=A.len;i++){
        if (A.data[i].row == 0&&A.data[i].col == 0&&A.data[i].num ==0){
            break;
        }
        if (A.data[i].num!=0){
        printf("%d %d %d\n",A.data[i].row,A.data[i].col,A.data[i].num);

        }
       

    }
   
}
void master(){
    TSMatrix A,B;
    int row,col,num,m,n;
    scanf("%d%d",&m,&n);
    initialTSM(&A,m,n);
    while(scanf("%d%d%d",&row,&col,&num)){
        if (row == 0 && col == 0 && num == 0){
            break;
        }
        appendTSM(&A,row,col,num);
    }
    scanf("%d%d",&m,&n);
    initialTSM(&B,m,n);
    while(scanf("%d%d%d",&row,&col,&num)){
        if (row == 0&& col == 0 && num ==0){
            break;
        }
        appendTSM(&B,row,col,num);
    }
    TSMatrix C = calculateTSM(A,B);
    outputTSM(C);
}
int main(){
    master();
    return 0;
}