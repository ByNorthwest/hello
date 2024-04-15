#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef struct {
    int ele[MAXSIZE];
    int rear;
    int front;
    int length;
}Queue;
int len;
void initial(Queue *que){
    que->length = 0;
    que->rear = 0;
    que->front = 0;
}

void EnterQueue(Queue *que,int a){
  
        que->length ++;
        que->ele[que->rear] = a;
        que->rear = (que->rear+1)%MAXSIZE;

    
}

int  gettop(Queue * que){
    return que->ele[que->front];
}
void DeletQueue(Queue *que){
    if(que->length == 0){
        return;
    }else{
        que->length --;
        que->front = (que->front + 1)%MAXSIZE;
    }
}
int  getnumber(char *a,int m){
        int v=0;
    for(int i=0;i<m;i++){
        int b = a[i] - 48;
        v +=b * (i+1);
    }
    return v;
}
void SeqQueue(){
    Queue qu;
    initial(&qu);
    int a,i=0;
    char s;
    char b[100] ;
            int m=0;
      scanf("%c",&s);
    while(scanf("%c",&s)&& s!='\n'){
    
            m=0;
            if(s!=' '){
                b[m] = s;
                m++;
                continue;
            }else{
        a = getnumber(b,m);
        EnterQueue(&qu,a);
        i++;
        } 
    } 
    a = getnumber(b,m);
    EnterQueue(&qu,a);
    i++;
    scanf("%d",&a);
    while(qu.ele[qu.front] !=a){
        DeletQueue(&qu);
    }
    if(i ==len){
        printf("yes");
    }else{
        printf("no");
    }
    printf("\n");
    DeletQueue(&qu);
    int g = gettop(&qu);
    while(qu.length !=0){
        printf("%d ",gettop(&qu));
        DeletQueue(&qu);
    }
    printf("\n%d",g);
}
int main(){
    scanf("%d",&len);
    SeqQueue();
    return 0;
}