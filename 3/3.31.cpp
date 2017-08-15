#include<stdio.h>
#include<stdlib.h>
#define INFEASIBLE -1//参数不合法
#define OK 1
#define ERROR 0 
#define OVERFLOW -2
typedef char ElemType;
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




/****stack****/
//栈的顺序表实现
#define STACK_INT_SIZE 100
#define STACKINCREMENT 50
typedef struct{
  ElemType *data;//动态数组
  int top;//栈顶
  int stacksize;//当前已分配的存储空间大小
}Stack;
Status InitStack(Stack &S);
Status DestroyStack(Stack &S);
Status ClearStack(Stack &S);
Status StackEmpty(const Stack &S);
int StackLength(const Stack &S);
Status GetTop(const Stack &S,ElemType &e);
Status Push(Stack &S,ElemType e);
Status Pop(Stack &S,ElemType &e);
ElemType Pop(Stack &S);

Status InitStack(Stack &S){
	S.data=(ElemType*)malloc(sizeof(ElemType)*STACK_INT_SIZE);
	S.stacksize=STACK_INT_SIZE;
	S.top=0;
}
Status StackEmpty(const Stack &S){
	return S.top==0;
}
Status GetTop(const Stack &S,ElemType &e){
	if(S.top==0)return ERROR;
    e=S.data[S.top-1];
    return OK;
}
Status Push(Stack &S,ElemType e){
	if(S.top==S.stacksize){
		S.data=(ElemType*)realloc(S.data,(S.stacksize+STACKINCREMENT)*sizeof(ElemType));
		if(!S.data)return OVERFLOW;
		S.stacksize+=STACKINCREMENT;
	}
    S.data[S.top++]=e;
}
Status Pop(Stack &S,ElemType &e){
	if(S.top==0)return ERROR;
    e=S.data[--S.top];
    return OK;
}
ElemType Pop(Stack &S){
	if(S.top==0){printf("Stack is empty\n"); exit(-1);}
	return S.data[--S.top];
}

Status DestroyStack(Stack &S){
	free(S.data);
	S.stacksize=0;
	S.top=0;
	return OK;
}
Status ClearStack(Stack &S){
	S.top=0;
	return OK;
}
int StackLength(const Stack &S){

	return S.top;
}
bool fun3_31(char str[]){
	int i=0;
	Stack S;InitStack(S);
	Queue Q;InitQueue(Q);
	while(str[i]!='@'){
		Push(S,str[i]);
		EnQueue(Q,str[i]);
		i++;
	}
	while(!StackEmpty(S)){
		if(Pop(S)!=DeQueue(Q))
			return false;
	}
	return true;

}



int main(){
	char str[200];
	while(true){
		scanf("%s",str);
		if(fun3_31(str))
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}