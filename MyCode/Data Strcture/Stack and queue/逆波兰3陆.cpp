#include<stdio.h>
#include<stdlib.h>
#define max 1000
#define ok 1
#define error 0
typedef struct DNode
{
    char a[max];
    int top;//栈顶元素的下标

}Stack;
void InitStack(Stack *s)
{
    s->top=-1;//构造空栈
}
int Push(Stack*s,char x)//进栈函数
{
    if(s->top==max-1) return error;
    s->top++;
    s->a[s->top]=x;
    return ok;
}
int Pop(Stack*s,char *x)//将栈顶元素放到x中弹出
{
    if(s->top==-1) return error;
    else
    {
        *x=s->a[s->top];
        s->top--;
        return ok;
    }
}
int StackEmpty(Stack *s)//检查栈是否为空
{
    if(s->top==-1) return ok;
    else return error;
}
char Top(Stack *s)//读取栈顶元素
{
  if(s->top==-1) return error;
    else
    {
        char x=s->a[s->top];
        return x;
    }
}
  char *RPExpression(char *e)
  /* 返回表达式e的逆波兰式 */
  {
     //栈s1用于存放运算符，栈s2用于存放逆波兰式
     Stack s1,s2;
     InitStack(&s1);
     InitStack(&s2);

     //假设字符'#'是运算级别最低的运算符，并压入栈s1中
     Push(&s1,'#');

     //p指针用于遍历传入的字符串，ch用于临时存放字符,length用于计算字符串长度
     char *p=e,ch;
     int length=0;
     for(;*p!='\0';p++)//逐个字符访问
     {
         switch(*p)
         {
             //遇'('则直接入栈s1
             case '(':
                 Push(&s1,*p);
                 break;
             //遇')'则将距离栈s1栈顶的最近的'('之间的运算符，逐个出栈，依次送入栈s2,此时抛弃'('
             case ')':
                 while(Top(&s1)!='(')
                 {
                     Pop(&s1,&ch);
                     Push(&s2,ch);
                 }
                 Pop(&s1,&ch);
                 break;
             //遇下列运算符，则分情况讨论：
             //1.若当前栈s1的栈顶元素是'('，则当前运算符直接压入栈s1；
             //2.否则，将当前运算符与栈s1的栈顶元素比较，若优先级较栈顶元素大，则直接压入栈s1中,
             //  否则将s1栈顶元素弹出，并压入栈s2中，直到栈顶运算符的优先级别低于当前运算符，然后再将当前运算符压入栈s1中
             case '+':
             case '-':
                 for(ch=Top(&s1);ch!='#';ch=Top(&s1))
                 {
                     if(ch=='(')
                     {
                         break;
                     }
                     else
                     {
                         Pop(&s1,&ch);
                         Push(&s2,ch);
                     }
                 }
                 Push(&s1,*p);
                 length++;
                 break;
             case '*':
             case '/':
                 for(ch=Top(&s1);ch!='#'&&ch!='+'&&ch!='-';ch=Top(&s1))
                 {
                     if(ch=='(')
                     {
                         break;
                     }
                     else
                     {
                         Pop(&s1,&ch);
                         Push(&s2,ch);
                     }
                 }
                 Push(&s1,*p);
                 length++;
                 break;
             //遇操作数则直接压入栈s2中
             default:
                 Push(&s2,*p);
                 length++;
         }
     }
     //若栈s1非空，则将栈中元素依次弹出并压入栈s2中
      while(!StackEmpty(&s1)&&Top(&s1)!='#')
     {
         Pop(&s1,&ch);
         Push(&s2,ch);
     }
     //最后将栈s2输出，逆序排列成字符串;
     char *result;
     result=(char *)malloc(sizeof(char)*(length+1));
     result+=length;
     *result='\0';
     result--;
     for(;!StackEmpty(&s2);result--)
     {
         Pop(&s2,&ch);
         *result=ch;
     }
     ++result;
     return result;
 }
int main()
{
    char e[max];char *r;
    scanf("%s",e);
    r = (char*)malloc(sizeof(char)*max);
    r=RPExpression(e);
    puts(r);
    return 0;

}
