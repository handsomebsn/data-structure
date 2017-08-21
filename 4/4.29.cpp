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
void showend(PtrNode p){
	while(p)
	{
		printf("%c", p->data);
		p=p->succ;
	}
}
Status Next(String t){
	PtrNode i,j;
	i=t->succ;
	if(!i)return ERROR;
	i->next=t;//next[i]=-1
	j=t;//j=-1
	while(i){
		if(j==t||i->data==j->data)
		{	
			//printf("%c",i->data);
			i=i->succ;
			j=j->succ;
			if(i)//zhuyi zhe yi ju
			i->next=j;//next[i]=j
		}else
		j=j->next;//j=next[j]
	}
}


PtrNode kmp(String s,String t){
	PtrNode i,j;
	i=s->succ;
	j=t->succ;
	Next(t);
	//printf("hahahahah\n");
	while(i&&j){
		if(j==t||i->data==j->data)
		{
			i=i->succ;
			j=j->succ;
		}else
		j=j->next;//j=next[j]	
	}
	if(!j)
		return i;
	else
		NULL;
}
int main(){
	String s,t;
	InitString(s);
	InitString(t);
	AddEnd(s,"iloveloveyou");
	AddEnd(t,"love");
	//show(t);
	Next(t);
	kmp(s,t);
	showend(kmp(s,t));
	return 0;
}