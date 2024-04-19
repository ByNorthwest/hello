# 3.4
(1)
将栈S反方向排序
(2)
借助栈T，使栈S中元素值等于e的元素弹出，其他元素顺序不变

# 3.5
一般准则：对于每一次进行操作之前，S操作的数量必须大于X操作的数量
证明：当这两个合法的栈操作序列长度不同时，输出序列的长度必定会不同，此时输出元素不相同。当这两个合法栈操作长度相同时，即两个栈操作内排列顺序不一样，此时每个X操作对应S操作的元素实体不一样，所以输出序列中元素实体输出不同。

# 3.15
void inistack(DqStack * tws){
    tws->top[0] = -1;
    tws->top[1] = M;
}

int  push (DqStack *tws , int i , ElemType x){//传入tws地址
    //当栈满时
    if (tws->top[0]+1 == tws->top[1]){
        return 0;//返回0，即栈满操作失败
    }else{
        if (i){
            tws->top[1] --;
            tws->Stack[tws->top[1]] = x;
            return 1;
        }else{
            tws->top[0]++;
            tws->Stack[tws->top[0]] = x;
            return 1;
        }
    }
}


int pop(DqStack * tws, int i){
    //当栈为空时则操作失败，分情况讨论
    if(i){
        if(tws->top[1] == M){
            return 0;
        }else{
            tws->top[1]++;
            return 1;
        }

    }else{
        if(tws->top[0] == -1)
            return 0;
        else{
            tws->top[0] --;
            return 1;
        }
    }
}


# 3.21
void Calcualte(Stack * sign,Stack * numbers){
    initial(&sign);
    initial(&numbers);
    char ch;
    int a,b;
    while(ch != '#'){
        scanf("%d", &a);
        ch = getchar();
        scanf("%d",&b);
        push(&numbers,a);
        push(&numbers,b);
        push(&sign,ch);
    }
    while(!IsEmpty(sign)&&!IsEmpty(numbers)){
        pop(&numbers,a);
        pop(&numbers,b);
        pop(&sign,ch);
        printf("%d %d% c",a,b,ch);
    }
}
# 3.28
typedef struct Node{
    ElemType data;
    Node * next;
}QueueNode;
typedef struct {
    QueueNode * rear;
}QueueList;

void initial(QueueList * L){
    //将L初始化为一个空的链表
    L->rear = (QueueList)malloc(sizeof(QueueNode));
    L->rear->next = L ->rear;
}//建立一个循环链表

void push(QueueList L,ElemType x){
    QueueNode * temp ;
    if(L->rear->next ==L->rear){
        temp =(QueueList)malloc(QueueNode);
        L->rear->next = temp;
        temp->next = L->rear;
        temp->data = x;
    }eles{
        temp =(QueueList)malloc(sizeof(QueueNode));
        temp->next = L->rear->next;
        temp->data =x;
        L->rear->next = temp;
        L->rear = temp;
    }
}

void pop(QueueList L){
    QueueNode * temp;
    temp = L->rear->next->next;
    L->rear->next->next = L->rear->next->next->next;
    free(temp);
}

# 3. 29
//设计一个循环队列，通过取余来使得队列空间得到充分利用
typedef struct {
    ElemType element[MAXSIZE];
    int front;
    int rear;
}SeqQueue;
int tag;//设为全局变量，初始化自动为0，表示队列区域未满；
void initial(SeqQueue * que){
    que->front = que->rear=0;
}
int push(SeqQueue * que, ElemType x){
    //先判断队列区域是否已满
    if (tag && que->front == que->rear ){
        return FALSE
    }
    que->element[que->rear] = x;
    que->rear = (que->rear+1)%MAXSIZE;
    if (que->rear == que->front){
        tag =1;
    }
    return TRUE
}

int pop(SeqQueue * que){
    if(!tag && que->front == que->rear){
        return FALSE;
    }else{
        que->front=(que->front+1)%MAXSIZE;
        tag = 0;
        return TRUE
    }
}
