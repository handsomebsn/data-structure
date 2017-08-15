#include<stdio.h>
#include<stdlib.h>
#define INFEASIBLE -1//参数不合法
#define OK 1
#define ERROR 0 
#define OVERFLOW -2
//
#define MAX 99999999
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
	int length;
}Queue;

Status InitQueue(Queue &q){
	q.front=q.rear=(Ptrnode)malloc(sizeof(Node));
	if(!q.front)return OVERFLOW;
	q.front->next=NULL;
	q.length=0;
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
	//
	q.length++;
	return OK;
}
Status DeQueue(Queue &q,ElemType &x){
	if(q.front==q.rear)return ERROR;
	x=q.front->next->data;
	Ptrnode tmp=q.front->next;
	q.front->next=tmp->next;
	free(tmp);
	//
	q.length--;
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

int QueueLength(const Queue &q){
	return q.length;
} 
ElemType Queuesum(const Queue &q){
	ElemType sum=0;
	Ptrnode p=q.front->next;
	while(p){
		//printf("hahah\n");
		sum+=p->data;
		p=p->next;
	}
	return sum;
}
void travel(const Queue &q){
	ElemType sum=0;
	Ptrnode p=q.front->next;
	while(p){
		printf("%d\n",p->data);
		p=p->next;
	}
}


void fun3_32(int k,Queue &fib){
	Queue q;
	InitQueue(q);
	for(int i=0;i<k-1;i++)
	{
		EnQueue(q,0);
		EnQueue(fib,0);
	}
	EnQueue(q,1);
	EnQueue(fib,1);
	int sum=Queuesum(q);
	while(sum<=MAX){
		EnQueue(fib,sum);
		EnQueue(q,sum);
		DeQueue(q);
		sum=Queuesum(q);
	}
	DestoryQueue(q);
}



int main(){

	Queue fib;
	InitQueue(fib);
	fun3_32(2,fib);
	travel(fib);
	DestoryQueue(fib);
	
	return 0;
}