#include<stdio.h>
#include<stdlib.h>
//最终还得是数学建模
//图形化理解其中的数学建模  图形化思想
 
typedef struct stack{
	struct stack *pop;
	struct stack *bottom;
	struct stack *next;
	char sign;
}stack; 
 
void init(stack *list){
    list->bottom = (stack*) malloc (sizeof(stack));
	list->bottom->next = NULL;
	list->pop = list->bottom;
}
 
void push(stack *list, char s){
    stack *p;
	p = (stack*)malloc(sizeof(stack));
	p->sign = s;
	p->next = list->pop;
	list->pop = p;
}
 
bool judge(char a, char b){
    if((a == '*' && (b == '+' || b == '-')) || (a == '/' && (b == '+' || b == '-')))
		return true;
	else
		return false;
}
 
void pop(stack *list){
    stack *p;
	p = list->pop;
	list->pop = list->pop->next;
	free(p);
}
 
int main(){
	char s,t;
	stack *list;
	list = (stack*) malloc (sizeof(stack));
	init(list);
	while(scanf("%c",&s) && s!='\n'){
		if(s >= 'a' && s <= 'z'){
		    printf("%c",s);
		}
		else if(s == '('){
		    push(list,s);
		}
		else if(s == ')'){
			while(list->pop->sign != '('){
				printf("%c",list->pop->sign);
			    pop(list);
			}
			pop(list);
		}
		else{
			while(1){
				t=list->pop->sign;
			    if(judge(s, list->pop->sign) || list->pop == list->bottom || list->pop->sign == '('){
		            push(list, s);
					break;
		        }
				else if(t == '+' || t == '-' || t == '*' || t == '/'){
				    printf("%c",list->pop->sign);
			        pop(list);
				}
				else{
					break;
				}
			}   
		}
	}
    while(list->pop != list->bottom){
    	printf("%c",list->pop->sign);
		pop(list);
    }
    printf("\n");
	return 0;
}