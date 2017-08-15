#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define INFEASIBLE -1//参数不合法
#define OVERFLOW -2
#define ERROR 0
#define OK 1
#define MAXQUEUESIZE 1000
typedef int ElemType;
typedef int Status;//函数状态
typedef struct
{
	ElemType *base;
	int rear;
	int length;
}Queue;
Status InitQueue(Queue &q){
	q.base=(ElemType*)malloc(sizeof(ElemType)*MAXQUEUESIZE);
	if(!q.base)return OVERFLOW;
	q.length=0;
	q.rear=-1;
	return OK;
}

Status add(Queue &q,ElemType x){
	if(q.length==MAXQUEUESIZE)return ERROR;
	q.rear=(q.rear+1)%MAXQUEUESIZE;
	q.base[q.rear]=x;
	q.length++;
	return OK;
}
Status del(Queue &q,ElemType &x){
	if(q.length==0)return ERROR;
	x=q.base[(q.rear+MAXQUEUESIZE-q.length+1)%MAXQUEUESIZE];
	q.length--;
}


int main(){
	Queue q;
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

