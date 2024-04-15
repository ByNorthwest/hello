#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int row,col,num;
    struct Node *down,*right;
}Node,*LNode ;
typedef struct {
    LNode * row_head,col_head;
    int m,n,len;
}CrossList;

void createCross(CrossList * A,int m,int n,int num){
    A->m = m;
    A->n = n;
    A->row_head = (LNode *)malloc((m+1)*sizeof(LNode));
    A->col_head = (LNode *)malloc((n +1)*sizeof(LNode));
    for(int i=1 ;i <= num;i++){
        if ()
    }
}
void calculateCross(CrossList * A, CrossList B){

}
void outputCross(CrossList A){
    for(int i =1 ;i <= A.m ;i++){
        while(A.row_head[i]!= NULL){
            printf("%d %d %d\n",A.row_head[i]->row,A.row_head[i]->col,A.row_head[i]->num);
            A.row_head[i] = A.row_head[i] ->right;
        }
    }
}
void master(){
    CrossList A,B,C;
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