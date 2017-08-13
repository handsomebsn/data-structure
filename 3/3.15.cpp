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
typedef int SElemType;

typedef struct{
  SElemType *data;//动态数组
  int top0;//栈顶
  int top1;
  int stacksize;//当前已分配的存储空间大小
}SqStack;
Status InitStack(SqStack &S);

Status InitStack(SqStack &S){
	S.data=(SElemType*)malloc(sizeof(SElemType)*STACK_INT_SIZE);
	S.stacksize=STACK_INT_SIZE;
	S.top0=-1;
	S.top1=S.stacksize;
}


Status Push(SqStack &S,int i,SElemType x){
	if(S.top0+1==S.top1)return ERROR;
	if(i==0){
		S.data[++S.top0]=x;
	}else if(i==1){
		S.data[--S.top1]=x;
	}
}
SElemType Pop(SqStack &S,int i){
	 if(i<0||i>1)return INFEASIBLE;
	if((i=0&&S.top0==-1)||(i=1&&S.top1==S.stacksize))return ERROR;
	if(i==0){
		return S.data[S.top0--];
	}else if(i==1){
		 return S.data[S.top1++];
	}
}