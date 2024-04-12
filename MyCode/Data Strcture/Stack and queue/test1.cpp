#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef struct {
    char ele[MAXSIZE];
    int top;
}Stack;
void initial (Stack * st ){
    st->top = -1;
}
void push(Stack * st,char ch){
    if (st->top ==MAXSIZE -1){
        return ;
    }else{
        st->top ++;
        st->ele[st->top] = ch;
    }
}
void pop (Stack * st){  
   
        st->top--;
    
}
int Match(char a,char b){
    if(a == '(' && b == ')'){
        return 1;
    }
    if (a =='{' && b == '}'){
        return 1;
    }
    if(a == '[' && b == ']'){
        return 1;
    }
    return 0;
}
void GetTop(Stack st,char *ch){
    *ch = st.ele[st.top];
}
int  IsEmpty(Stack st){
    if (st.top == -1){
        return 1;
    }else{
        return 0;
    }
}
int BracketMatch(char *str){
    Stack st;
    char ch;
    initial(&st);
    for(int i=0;str[i]!='\0';i++){
        switch (str[i]){
            case '{':
            case '[':
            case '(':
                push(&st,str[i]);
                break;
            case ']':
            case ')':
            case '}':
                if (IsEmpty(st)){
                    return 0;
                }else{
                    GetTop(st,&ch);
                    if(Match(ch,str[i])){
                        pop(&st);
                    }else{
                        return 0;
                    }
                }
        }
    }
    if(IsEmpty(st)){
        return 1;
    }else{
        return 0;
    }
}
int main(){
    char str[MAXSIZE];
    scanf("%s",str);
    if(BracketMatch(str)){
        printf("yes");

    }else{
        printf("no");
    }
    return 0;
    
}