#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define LIST_INT_SIZE 100
#define LISTINCREMENT 10
#define INFEASIBLE -1//参数不合法
#define OK 1
#define OVERFLOW -2
#define ERROR 0
typedef int ElemType;
typedef int Status;//函数状态
typedef struct LNode{
  ElemType data;
  struct LNode *next;
}LNode,*LinkList,*ptrlnode;//线性链表类型


typedef ptrlnode Queue_rear;


Status InitQueue(Queue_rear &qrear){
	qrear=(Queue_rear)malloc(sizeof(LNode));
	if(!qrear)return OVERFLOW;
	//qrear->data=-999;
	qrear->next=qrear;
	return OK;
}


Status add(Queue_rear &qrear,ElemType x){
	ptrlnode newptr=(ptrlnode)malloc(sizeof(LNode));
	if(!newptr)return OVERFLOW;
	newptr->data=x;
	newptr->next=qrear->next;
	qrear->next=newptr;
	qrear=newptr;
	return OK;
}


Status del(Queue_rear qrear,ElemType &x){
	if(qrear->next==qrear)return ERROR;
	qrear=qrear->next;

	x=qrear->next->data;
	ptrlnode tmp=qrear->next;
	qrear->next=tmp->next;
	free(tmp);
}

int main(){
	Queue_rear q;
	InitQueue(q);
	srand(time(NULL));
	int x;
	for(int i=0;i<10;i++){
		x=rand()%100;
		printf("%d ",x);
		add(q,x);
	}
	printf("\n");
	for(int i=0;i<10;i++){
		del(q,x);
		printf("%d ",x);
		
	}


	return 0;
}


