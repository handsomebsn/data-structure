#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define INFEASIBLE -1//参数不合法
#define OK 1
#define ERROR 0 
#define OVERFLOW -2
typedef int ElemType;
typedef int Status;//函数状态
//栈的顺序表实现
#define STACK_INT_SIZE 100
#define STACKINCREMENT 50
typedef char SElemType;

typedef struct{
  SElemType *data;//动态数组
  int top;//栈顶
  int stacksize;//当前已分配的存储空间大小
}SqStack;
Status InitStack(SqStack &S);
Status DestroyStack(SqStack &S);
Status ClearStack(SqStack &S);
Status StackEmpty(const SqStack &S);
int StackLength(SqStack &S);
Status GetTop(const SqStack &S,SElemType &e);
Status Push(SqStack &S,SElemType e);
Status Pop(SqStack &S,SElemType &e);

Status InitStack(SqStack &S){
	S.data=(SElemType*)malloc(sizeof(SElemType)*STACK_INT_SIZE);
	S.stacksize=STACK_INT_SIZE;
	S.top=0;
}
Status StackEmpty(const SqStack &S){
	return S.top==0;
}
Status GetTop(const SqStack &S,SElemType &e){
	if(S.top==0)return ERROR;
    e=S.data[S.top-1];
    return OK;
}
Status Push(SqStack &S,SElemType e){
	if(S.top==S.stacksize){
		S.data=(SElemType*)realloc(S.data,(S.stacksize+STACKINCREMENT)*sizeof(SElemType));
		if(!S.data)return OVERFLOW;
		S.stacksize+=STACKINCREMENT;
	}
    S.data[S.top++]=e;
}
Status Pop(SqStack &S,SElemType &e){
	if(S.top==0)return ERROR;
    e=S.data[--S.top];
    return OK;
}
Status DestroyStack(SqStack &S){
	free(S.data);
	S.stacksize=0;
	S.top=0;
}
///////////////////////////////////////////////////
Status fun3_16(char chexiang[],char con[]){//con 车厢调度的操作序列
	int i=0;
	int j=0;
	SqStack S;
	InitStack(S);
	while(chexiang[i]!='\0'){
		if(chexiang[i]=='H'){
			Push(S,'H');
			con[j++]='I';
		}else if(chexiang[i]=='S'){
			//Push(S,'S');
			//Pop(S,kk);
			con[j++]='I';
			con[j++]='O';

		}
		i++;
	}
	char tmp;
	while(!StackEmpty(S)){
		Pop(S,tmp);
		con[j++]='O';
	}
	con[j]='\0';
}
int main(){
	char chexiang[]="HSHSSSHSHSHSHSHSHSHSHSSSHSHH";
	char con[1000];
	fun3_16(chexiang,con);
	printf("%s\n",con );

	return 0;
}
