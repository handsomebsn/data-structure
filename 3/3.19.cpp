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

/////////////////
bool fun3_19(char str[]){
	SqStack S;
	InitStack(S);
	char c;
	int i=0;
	while(str[i]){
	switch(str[i]){
		//default: ;
		case '(':

		case '[':

		case '{':
		//printf("aaa\n");
Push(S,str[i]);break;

	}
	if(!StackEmpty(S)){
		switch(str[i]){

		case ')':Pop(S,c);if(c!='(')return ERROR; break;

		case ']':Pop(S,c);if(c!='[')return ERROR;break;

		case '}':Pop(S,c);if(c!='{')return ERROR;break;

		}

	}
	i++;
 }
    if(StackEmpty(S))
    	return OK;
    else
    	return ERROR;


}


int main(){
	char a[]="{[(abc)]}(";
if(fun3_19(a))
	printf("OK\n");
else
	printf("ERROR\n");
	return 0;
}