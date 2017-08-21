#include<stdio.h>
#include<malloc.h>
#define INFEASIBLE -1//参数不合法
#define OK 1
#define ERROR 0 
#define OVERFLOW -2
typedef char ElemType;
typedef int Status;//函数状态
typedef struct Node
{
	ElemType data;
	struct Node *succ;
	struct Node *next;
}Node,*PtrNode;

typedef PtrNode String;
Status InitString(String &s){
	s=(String)malloc(sizeof(Node));
	if(!s)return OVERFLOW;
	s->succ=NULL;
	s->data='!';
	s->next=NULL;
	return OK;
}
Status AddEnd(String s,const char *t){
	PtrNode rear=s;
	PtrNode newptr;
	while(rear->succ)rear=rear->succ;
	int i=0;
	while(t[i]){
	newptr=(PtrNode)malloc(sizeof(Node));
	newptr->data=t[i];
	newptr->succ=NULL;
	newptr->next=rear;
	rear->succ=newptr;
	rear=newptr;
	i++;
	}
}
void show(String s){
	PtrNode p=s->succ;
	while(p)
	{
		printf("%c", p->data);
		p=p->succ;
	}
}
//子串第一个元素和主串游标所指向的元素.....不相等，则主串和子串游标都要右移一位再比较

Status Next(String t){
	PtrNode i,j;
	i=t->succ;
	if(!i)return ERROR;
	i->next=t;//next[i]=-1
	j=t;//j=-1
	while(i){
		//printf("%c\n", i->data);
		if(j==t||i->data==j->data)//j==-1||[i]==[j]
		{
			i=i->succ;//++i
			j=j->succ;//++j
			if(i)//zhuyi yao zhe yiju
			i->next=j;//next[i]=j
		}else
		j=j->next;//j=next[j]回溯
	}
}

int main(){
 	String s;
 	InitString(s);
 	AddEnd(s,"abcde");
 	show(s);
 	printf("\n");
 	Next(s);

	return 0;
}
