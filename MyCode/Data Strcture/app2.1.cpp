#include<stdio.h>
#include<stdlib.h>
#define size 100
typedef struct Node{
    char data[size];
    int top;
}DqStack;
void push(DqStack *m,char q){
    if (m->top == size -1){
        return;
    }else{
        m->top ++;
        m->data[m->top] = q;
    }
}
void pop(DqStack *m){
    if(m->top == -1){
        return;
    }else{
        m->data[m->top]=0;
        m->top--;
    }
}
int  Match(char *string,DqStack *m){
    
}
int main(){
    char *string;
    scanf("%s",string);
    DqStack * header;
    header->top = -1;
    if(Match(string,header)){
        printf("yes");
    }else{
        printf("no");
    }
    return 0;
}