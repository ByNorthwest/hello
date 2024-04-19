#include<stdio.h>
#include<stdlib.h>
#define  MAXSIZE  100
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

void pop (Stack *st ,char *ch){
    if ( st->top == -1)exit(0);
    *ch = st->ele[st->top];
    st->top--;
}
int StackEmpty(Stack *st){
    if (st->top == -1){
        return 1;
    }else{
        return 0;
    }
}
char gettop(Stack *st){
    return st->ele[st->top];
}
//需要判断运算符优先级


char * ReverPolan(char *str){
    Stack s1,s2;//s2用来存放逆波兰表达式
    initial(&s1);
    initial(&s2);
    int ptr=0,length = 0;
    char temp;
    for(ptr=0;str[ptr]!='\0';ptr++){
        switch (str[ptr]){
            case '(':
                push(&s1,str[ptr]);
                break;
            case ')':
                while(gettop(&s1)!='('){
                    pop(&s1,&temp);
                    push(&s2,temp);
                }
                pop(&s1,&temp);
                break;
            case '+':
                for(;!StackEmpty(&s1);){
                    if(gettop(&s1)=='('){  
                        break;
                    }else{
                        pop(&s1,&temp);
                        push(&s2,temp);
                    }
                }
                push(&s1,str[ptr]);
                length++;
                break;
                case '*':
                case '/':
                while(gettop(&s1) !='+' && gettop(&s1) !='-'){
                    if (gettop(&s1) == '('){
                        break;
                    }else{
                        pop(&s1,&temp);
                        push(&s2,temp);
                    }
                }
                push(&s1,str[ptr]);
                length++;
                break;
            default:
                push(&s2,str[ptr]);
                length++;
        }
    }
    while(!StackEmpty(&s1)){
        pop(&s1,&temp);
        push(&s2,temp);
    }
    char *max;
    max = (char *)malloc(sizeof(char)*(length+1));
    max +=length;
    *max='\0';
    max--;
    for(;!StackEmpty(&s2);max--){
        pop(&s2,&temp);
        *max = temp;
    }
    ++max;
    return max;
   
}


int main(){
    char str[MAXSIZE],*ptr;
    ptr = (char*)malloc(MAXSIZE);
    scanf("%s",str);
    ptr = ReverPolan(str);
    puts(ptr);
    return 0;
}