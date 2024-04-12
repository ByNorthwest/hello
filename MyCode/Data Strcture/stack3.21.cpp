#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    char data;
    Node * next;
}DqStack,*DqList;
void initial(DqList *s,char c){
    DqStack * p;
    p = (DqStack *)malloc(sizeof(DqStack));
    while((*s)->next){
        *s = (*s)->next;
    }
    (*s)->next = p;
    p ->next = NULL;
    p->data = c;
}
void reversePoland(DqList * s ){
    DqStack * ptr  = (*s)->next;
    while(ptr->next){
        ptr = ptr->next;
    }
    while(ptr == (*s)->next){
        char u = ptr ->data;
        
    }
    
}
int main(){
    DqList header;
    header = (DqList)malloc(sizeof(DqStack));
    header ->next = NULL;
    while (scanf("%c",&c)){
        initial(&header,c);
    }
    return 0;
}