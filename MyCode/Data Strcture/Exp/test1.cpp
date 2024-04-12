#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *pre;
    struct Node *next;
} Dnode, *Dhead;
void create(Dhead head, int data)
{
    Dhead header = head;
    while (header->next != NULL)
    {
        header = header->next;
    }
    Dnode *newnode = (Dnode *)malloc(sizeof(Dnode));
    header->next = newnode;
    newnode->pre = header;
    newnode->data = data;
    newnode->next = NULL;
}
void tranverselist(Dhead header, int length)
{
    Dhead p = header;
    p = p->next;
    printf("%d", p->data);
    int i;
    p = p->next;
    for (i = 0; i < length; i++)
    {
        printf("%d", p->data);
        if (p->next)
        {
            p = p->next;
        }
    }
    printf("\n");
}
int main()
{
    Dhead head;
    Dhead ak;
    head = (Dnode *)malloc(sizeof(Dnode));
    ak = (Dnode *)malloc(sizeof(Dnode));
    head->pre = NULL;
    head->next = NULL;
    ak->pre = NULL;
    ak->next = NULL;

    int length;
    scanf("%d", &length);
    int i;
    for (i = 0; i < 600; i++)
    {
        create(head, 0);
        create(ak, 0);
    }
    Dhead p1 = head->next;
    Dhead p2 = ak->next;
    // 使两个链表出头节点外第一个接待你的数据为2，直接从R2开始计算，简化了计算
    p1->data = 2;
    p2->data = 2;
    // 指向head,ak 的尾节点
    while (p1->next)
    {
        p1 = p1->next;
    }
    Dhead tail = p1;
    while (p2->next)
    {
        p2 = p2->next;
    }
    Dhead tail2 = p2;
    // 现在开始运算
    int temp = 0;
    int ret = 0;
    int t;
    for (i = 1, t = 3; i < 10000; i++, t = t + 2)
    {
        Dhead p3 = tail;
        ret = 0;
        while (p3)
        {
            temp = p3->data * i + ret;
            p3->data = temp % 10;
            ret = temp / 10;
            p3 = p3->pre;
        }
        ret = 0;
        p3 = head->next;
        // 计算除法，即公式中的
        while (p3)
        {
            temp = p3->data + ret % 10;
            ret = temp % t;
            p3->data = temp / t;
            p3 = p3->next;
        }
        ret = 0;
        Dhead p4 = tail2;
        p3 = tail;
        while (p3 && p4)
        {
            temp = p3->data + p4->data + ret;
            ret = temp / 10;
            p4->data = temp % 10;
            p3 = p3->next;
            p4 = p4->next;
        }
    }
    tranverselist(ak, length);
    return 0;
}
