#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define INFEASIBLE -1//
#define OVERFLOW -2
#define OK 1
#define ERROR 0 

#define MAXQUEUESIZE 100
typedef float ElemType;
typedef int Status;//函数状态


typedef struct
{
	ElemType *data;
	int front;
	int rear;
}Queue;
Status InitQueue(Queue &q){
	q.data=(ElemType*)malloc(sizeof(ElemType)*MAXQUEUESIZE);
	if(!q.front) return OVERFLOW;
	q.front=q.rear=0;
	return OK;
}

Status AddHead(Queue &q,ElemType x){
	if((q.front+MAXQUEUESIZE-1)%MAXQUEUESIZE==q.rear)return ERROR;
	q.front=(q.front+MAXQUEUESIZE-1)%MAXQUEUESIZE;
	q.data[q.front]=x;
	return OK;
}

Status AddEnd(Queue &q,ElemType x){
	if((q.rear+1)%MAXQUEUESIZE==q.front)return ERROR;
	q.data[q.rear]=x;
	q.rear=(q.rear+1)%MAXQUEUESIZE;
	return OK;
}

ElemType DelHead(Queue &q){
	ElemType x;
	if(q.front==q.rear){printf("Queue is empty \n");exit(-1);}
	x=q.data[q.front];
	q.front=(q.front+1)%MAXQUEUESIZE;
	return x;
}

ElemType GetHead(const Queue &q){
	if(q.front==q.rear){printf("Queue is empty \n");exit(-1);}
	return q.data[q.front];
}
ElemType GetEnd(const Queue &q){
	if(q.front==q.rear){printf("Queue is empty \n");exit(-1);}
	return q.data[(q.rear+MAXQUEUESIZE-1)%MAXQUEUESIZE];
}
bool QueueEmpty(const Queue &q){
	return q.front==q.rear;
}


Status fun3_33(Queue &q,ElemType x){
	if(QueueEmpty(q)){
		AddEnd(q,x);return OK;
	}

	if(x<(GetHead(q)+GetEnd(q))/2)
	{
      if(AddHead(q,x)==OK)return OK;
      else return ERROR;
	}else{

     if(AddEnd(q,x)==OK)return OK;
     else return ERROR;
	}

}
int main(int argc, char const *argv[])
{
	/* code */
	srand(time(NULL));
	Queue q;
	InitQueue(q);
	for(int i=0;i<10;i++)
		fun3_33(q,rand()%100);
	for(int i=0;i<10;i++)
		printf("%.0f ",DelHead(q));

	return 0;
}


