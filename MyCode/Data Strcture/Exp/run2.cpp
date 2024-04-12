#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node * next;
    struct Node * pre;
}Dnode,*Dhead;
void initialNode(Dhead head,int data){
    Dhead ptr = head;
    if(ptr==NULL){
        return ;
    }
    else{
        while(ptr->next){
            ptr=ptr->next;
        }
        Dhead newnode = (Dhead)malloc(sizeof(Dnode));
        newnode->data = data;
        ptr->next = newnode;
        newnode->pre= ptr;
        newnode->next = NULL;
    }
}
void print(Dhead head, int pres){//此处只是用一级指针是因为所谓的
//值传递是传递了一个指针，即一个地址，所以可以使用该地址进行地址的next 运算
//而且使用一级指针不会改变函数调用结束之后调用函数中head的值（即地址）只传一级指针即可
    Dhead ptr = head;
    ptr = ptr->next;
    printf("%d.",ptr->data);
    int i;
    ptr = ptr->next;
    for(i=0;i<pres;i++){
        printf("%d",ptr->data);
        if(ptr->next){
            ptr=ptr->next;
        }else{
            break;
        }
    }
    printf("\n");
}
void calculate(int pres){
    Dhead head1 = (Dnode*)malloc(sizeof(Dnode));
    Dhead head2 = (Dnode*)malloc(sizeof(Dnode));
    head1 ->pre  =NULL;head1->next= NULL;head2->pre=NULL;head2->next = NULL;
    int i;
    for(i=0;i<600;i++){
        initialNode(head1,0);
        initialNode(head2,0);
  }
    Dhead index1 = head1 ->next;
    Dhead index2 = head2->next;
    index1->data = 2;
    index2->data = 2;
    while(index1->next){
        index1 = index1->next;
    }   
    Dhead tail1 = index1;
    while(index2->next){
        index2 = index2->next;
    }
    Dhead tail2 = index2;
    int temp = 0;
    int forward = 0;
    int t;
    for(i=1,t = 3;i<10000;i++,t = t +2){
        Dhead ptrnew = tail1;
        forward = 0;
        while(ptrnew){
            temp = ptrnew->data*i+forward;
            ptrnew->data =temp%10;
            forward = temp/10;
            ptrnew = ptrnew->pre;

        }
        forward = 0;
        ptrnew = head1 ->next;
        while(ptrnew){
            temp = ptrnew->data +forward*10;
            forward = temp %t;
            ptrnew->data = temp/t;
            ptrnew = ptrnew->next;
        }
        forward = 0;
        Dhead indinew = tail2;
        ptrnew = tail1;
        while(ptrnew&&indinew){
            temp = ptrnew->data + indinew->data +forward;
            forward = temp/10;
            indinew->data = temp% 10 ;
            ptrnew = ptrnew->pre;
            indinew = indinew->pre;
         }
    }
    print(head2,pres);
}

int main(){
    int pres;
    scanf("%d",&pres);
    calculate(pres);
    return 0;
}