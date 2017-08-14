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
bool match(char a,char b){
	switch(a){
		case '(':return b==')';

		case '[':return b==']';

		case '{':return b=='}';

	}
}
int youxianji(char yunsuanfu){
	switch(yunsuanfu){
	case '+':
	case '-':
	return 0;break;
	case '*':
	case '/':
	return 1;break;
	}
}
int cmp(char yun1,char yun2){

	return youxianji(yun1)-youxianji(yun2);
}

bool iskuohao(char c){
	switch(c){
		case '[':
		case '{':
		case '(':
		case ']':
		case '}':
		case ')':
		return true;
		default:return false;
	}
}

Status fun3_21(char *str,char strto[]){
	SqStack S1,S2;
	InitStack(S1);
	InitStack(S2);
	int i=0;
	int ito=0;
	char tmp;
	bool on=true;
	while(str[i]!='\0'){

		if(isalpha(str[i]))
			strto[ito++]=str[i];
		else if(iskuohao(str[i])){
			switch(str[i]){
				case '(':

				case '[':

				case '{':
				Push(S2,str[i]);break;
			}
			if(!StackEmpty(S2)){
				GetTop(S2,tmp);
			switch(str[i]){
				case ')':

				case ']':

				case '}':
				if(match(tmp,str[i])){if(!StackEmpty(S1))Pop(S1,tmp);else return ERROR; strto[ito++]=tmp;Pop(S2,tmp);}break;

			}

			}
		}else {
			if(!StackEmpty(S1)&&StackEmpty(S2)){
				//printf("%c\n", str[i]);
				GetTop(S1,tmp);
				if(cmp(tmp,str[i])>=0){
					Pop(S1,tmp);
					Push(S1,str[i]);
					strto[ito++]=tmp;
				}else{
					Push(S1,str[i]);
				}


			}else{
				//printf("%c\n", str[i]);

				Push(S1,str[i]);
			}
		}
		i++;
	}
	//printf("aaaaa\n");
	while(!StackEmpty(S1)){
		Pop(S1,tmp);
		strto[ito++]=tmp;
	}
	strto[ito]='\0';
	return OK;
}




int main(){
	printf("enter zhong zhui biao da shi\n");
	char str[100];char strto[100];
	scanf("%s",str);
	fun3_21(str,strto);
	printf("%s\n", strto);
	return 0;
}