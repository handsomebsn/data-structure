#include<stdio.h>
#include<stdlib.h>
#define INFEASIBLE -1//参数不合法
#define OK 1
#define ERROR 0 
#define OVERFLOW -2
typedef int ElemType;
typedef int Status;//函数状态
typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node,*Ptrnode;

typedef struct
{
	Ptrnode front;
	Ptrnode rear;
}Queue;

Status InitQueue(Queue &q){
	q.front=q.rear=(Ptrnode)malloc(sizeof(Node));
	if(!q.front)return OVERFLOW;
	q.front->next=NULL;
	return OK;
}
Status DestoryQueue(Queue &q){
	while(q.front){
		q.rear=q.front->next;
		free(q.front);
		q.front=q.rear;
	}

}
Status EnQueue(Queue &q,ElemType x){
	Ptrnode p=(Ptrnode)malloc(sizeof(Node));
	if(!p)return OVERFLOW;
	p->data=x;
	p->next=q.rear->next;
	q.rear->next=p;
	q.rear=p;
	return OK;
}
Status DeQueue(Queue &q,ElemType &x){
	if(q.front==q.rear)return ERROR;
	x=q.front->next->data;
	Ptrnode tmp=q.front->next;
	q.front->next=tmp->next;
	free(tmp);
	return OK;
}
ElemType DeQueue(Queue &q){
	if(q.front==q.rear){printf("queue is empty\n");exit(-1);}
	ElemType x;
	x=q.front->next->data;
	Ptrnode tmp=q.front->next;
	q.front->next=tmp->next;
	if(q.rear==tmp) q.rear=q.front;
	free(tmp);
	return x;
}
int main(){

	Queue q;
	InitQueue(q);
	EnQueue(q,5);
	EnQueue(q,6);
	//printf("%d\n",Pop(S) );

   printf("%d\n",DeQueue(q) );
   printf("%d\n", DeQueue(q));
   DeQueue(q);
	return 0;
}