#include<stdio.h>
#include<stdlib.h>
#define  MAXSIZE  100
typedef struct { 
    char ele[MAXSIZE];
    int top;
}Stack;

void initial(Stack * st){
    st->top = -1;
    for(int i=0;i<MAXSIZE;i++)
{
    st->ele[i] = 0;
}}
void push(Stack *st,char ch){
    st->top++;
    st->ele[st->top] = ch;
}

void pop (Stack *st ,char *ch){
    if ( st->top == -1)exit(0);
    *ch = st->ele[st->top];
    st->top--;
}
char gettop(Stack *st){
    return st->ele[st->top];
}
//需要判断运算符优先级


void ReverPolan(char *str){
    Stack sign;
    Stack number;
    initial(&sign);
    initial(&number);
    int c = 0;
    //因为逆波兰式不需要括号，所以进栈时要把除了number与sign的其他括号去掉
    for(int i=0;str[i]!='\0';i++){
        if ((str[i]>96 && str[i] <=122)||str[i] ==40 ||str[i] ==41){
            push(&number,str[i]);
            
        }else if(str[i] == 42 || str[i] == 43 || str[i] == 45 || str[i] == 47){
            push (&sign,str[i]);
        
        }
        
    }
    for(int i=0;str[i]!='\0';i++){
        if(gettop(&number) !='('){
            char c;
            pop(&sign,&c);
            char m,n;
            if(proirity(c,gettop(&sign))){
                
                 pop(&number,&m);
                 pop(&number,&n);
                printf("%c%c%c",m,n,c);

            }else{
                pop(&number,&m);
                pop(&number,&n);
                char o,p;
                pop(&sign,&o);
                pop(&number,&p);
                printf("%c%c%c%c%c",m,c,n,o,p);
            }
        }else{
            char c;
            pop(&sign,&c);
            char m,n;
            pop(&number,&m);
            if(gettop(&number)!=')'){
            if(proirity(c,gettop(&sign))){
                
                 pop(&number,&m);
                 pop(&number,&n);
                printf("%c%c%c",m,n,c);

            }else{
                pop(&number,&m);
                pop(&number,&n);
                char o,p;
                pop(&sign,&o);
                pop(&number,&p);
                printf("%c%c%c%c%c",m,c,n,o,p);
            }
            }else{
                pop(&number,&m);
                
            }
        }
    }
}


int main(){
    char str[MAXSIZE];
    scanf("%s",str);
    ReverPolan(str);
    return 0;
}