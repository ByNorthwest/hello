#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct Node{
    int data;
    struct Node * pre;
    struct  Node * next;
}Dnode,*Dhead;

void initial(Dhead list,int data ){
    Dhead newnode = (Node*)malloc(sizeof(Node));
    newnode ->data=data;
    newnode->next = NULL;
    while(list->next){
        list = list->next;
    }
    list ->next= newnode;
    newnode ->pre = list;
    
}
void print(Dhead list,int pres){
    printf("3.");
    list = list->next;
    list = list ->next;
    int i=0;
    for(i=0;i<pres;i++){
        printf("%d",list->data);
       if(list->next){
        list=list->next;
       }else{
        break;
       }
    }
    printf("\n");
}

void calculate(int precision){
    Dhead head1=(Dnode*)malloc(sizeof(Dnode));
    Dhead head2=(Dnode*)malloc(sizeof(Dnode));
    head1 ->next =NULL;head2->next= NULL;head1->pre=NULL;head2->pre = NULL;
    int i=0;
    for(i=0;i<500;i++){
        initial(head1,0);
        initial(head2,0);
    }
    Dhead ptr1 = head1->next;
    Dhead ptr2 = head2->next;
    ptr1->data  = 2;
    ptr2->data = 2;
    while(ptr1->next){
        ptr1 = ptr1->next;
    }
    Dhead tail1 = ptr1;
    while(ptr2->next){
        ptr2 = ptr2->next;
    }
    Dhead tail2 =ptr2;
    int forward = 0;
    int back =0;
    int t;
    for(i=0,t=3;i<510;i++,t=t+2){
        Dhead temp1 = tail1;
        
    }
}

int main(){
    int precision;
    scanf("%d",&precision);
    calculate(precision);
    return 0;
}