#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 1000
typedef struct {
    int row,col;
    int num;
}Tripe;
typedef struct {
    Tripe data[MAXSIZE];
    int m,n,len;//矩阵的行，列和非零元个数
}TSMatrix; 
void initialTSM(TSMatrix *A,int n, int m){
    A->m=m;
    A->n=n;
    A->len = 0;
}
void outputTSM(TSMatrix A){
    for(int i =1;i <= A .len;i++){
        printf("%d %d %d\n",A.data[i].row,A.data[i].col,A.data[i].num);
        
    }

}
void tranTSM(TSMatrix A,TSMatrix * B){
    B->len = A.len;
    B->n = A.m;
    B->m = A.n;
    //number是col
    int number[MAXSIZE],position[MAXSIZE];
    for(int i=0;i<A.n;i++){
        number[i] =0;
    }
    for(int i=1;i<=A.len;i++){
        ++number[A.data[i].col] ;
    }
    position[0] = 1;
    for(int i=1;i<A.n;i++){
        position[i] = position[i-1] + number[i-1]; 
    }
    
    for(int i=1;i<=A.len;i++){
        int col = A.data[i].col;
        int q = position[col];
        B->data[q].num = A.data[i].num;
        B->data[q].col= A.data[i].row;
        B->data[q].row = A.data[i].col;
        ++position[col];
    }
}
void appendTSM(TSMatrix *A,int row,int col ,int num){
    A->len++;
    A->data[A->len].num = num;
    A->data[A->len].col = col;
    A->data[A->len].row = row;
}
void master(){
    int n,m;
    scanf("%d%d",&n,&m);
    int row,col,num;
    TSMatrix A;
    initialTSM(&A,n,m);
    while(scanf("%d%d%d",&row,&col,&num)){
        if (row == 0 && col == 0 && num == 0){
            break;
        }
        appendTSM(&A,row,col,num);
    }
    //进行一次定位转置稀疏矩阵A，创建稀疏矩阵B
    TSMatrix B;
    initialTSM(&B,n,m);
    tranTSM(A,&B);
    outputTSM(B);
}
int main(){
    master();
    return 0;
}
