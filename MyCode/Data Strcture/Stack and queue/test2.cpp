#include<stdio.h>
#include<stdlib.h>
#define  MAXSIZE  1000
typedef struct { 
    char ele[MAXSIZE];
    int top;
}Stack;

void initial(Stack * st){
    st->top = -1;
}

void push(Stack *st,char ch){
    st->top++;
    st->ele[st->top] = ch;
}

char pop (Stack *st ){
    char ch = st->ele[st->top];
    st->top--;
    return ch;
}

//需要判断运算符优先级


void ReverPolan(char *str){
    Stack sign;
    Stack number;
    initial(&sign);
    initial(&number);
    int c = 0;;
    //因为逆波兰式不需要括号，所以进栈时要把除了number与sign的其他括号去掉
    for(int i=0;str[i]!='\0';i++){
        if (str[i]>96 && str[i] <=122){
            push(&number,str[i]);
            c++;
        }else if(str[i] == 42 || str[i] == 43 || str[i] == 45 || str[i] == 47){
            push (&sign,str[i]);
            c++;
        }
        if(c == 3){
        char a = pop(&number);
        char b = pop(&number);
        printf("%c%c%c",b,a,pop(&sign));
        c=1;//注意到此时c是回到为1
        }
        
        
    }
}


int main(){
    char str[MAXSIZE];
    scanf("%s",str);
    ReverPolan(str);
    return 0;
}