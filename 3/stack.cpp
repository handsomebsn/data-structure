#include<stdio.h>
#include<stdlib.h>
#define INFEASIBLE -1//参数不合法
#define OK 1
#define ERROR 0 
#define OVERFLOW -2
typedef int ElemType;
typedef int Status;//函数状态
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

int main(){

	Stack S;
	InitStack(S);
	Push(S,5);
	Push(S,6);
	//printf("%d\n",Pop(S) );

   printf("%d\n",StackLength(S) );
	return 0;
}