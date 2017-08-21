#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
class string{
	private:
		char *str;
		int len;
		//const int initsize;
	public:
		string();
		string(char c);
		string(const char _str[]);
		string(const string &s);
		~string(){delete [] str;strnumber--;}
	static const int initsize;
	static int strnumber;
	static int number(){return strnumber;}
	/////////////////////////////////
	int length()const; 
	const char * c_str(){return str;}
	void print();
	int kmp(const string &t)const;
	///////////////////////////////////
	string& operator =(const string &s);
	string operator+(const string &s);
	////////////////////////////////////
	operator const char*(){return str;};
	

};
/*string::string():initsize(4){


}*/
const int string::initsize=4;
int string::strnumber=0;

string::string(){
	//printf("gouzao\n");
	str=new char[1];
	if(!str)throw("OVERFLOW");
	str[0]='\0';
	len=0;
	//
	strnumber++;
}

string::string(char c){
	len=1;
	str=new char[len+1];
	str[0]=c;
	str[1]='\0';
}


string::string(const char _str[]){
	//printf("gouzao\n");
	len=strlen(_str);
	str=new char[len+1];
	strcpy(str,_str);

	strnumber++;
}

string::string(const string &s){
	len=s.length();
	str=new char[len+1];
	strcpy(str,s.str);
	//printf("fuzhigouzaohanshu\n");
}

string& string::operator=(const string &s){
	len=s.length();
	str=new char[len+1];
	strcpy(str,s.str);
	//printf("--============--\n");
	return *this;
}
string string::operator+(const string &s){
	string newstr;
	char *tmp=newstr.str;
	/////////////////////////////////////
	newstr.len=length()+s.length();
 	newstr.str=new char[newstr.len+1];
 	strcpy(newstr.str,str);
    strcat(newstr.str,s.str);
    delete[]tmp;
	return newstr;
}

int string::length()const{
 return len;
}

void string::print(){
	printf("%s\n", str);
}


int string::kmp(const string &t)const{
	int i=0;
	int j=0;
	/////////////////////
	int *next=new int[t.len];
	next[0]=-1;j=-1;
	while(i<t.len){
		if(j==-1||t.str[i]==t.str[j]){
			++i;
			++j;
			next[i]=j;
		}else
		j=next[j];
	}
	///////////////////////
    i=0;j=0;
	while(i<len&&j<t.len){
		if(j==-1||str[i]==t.str[j])
		{
			++i;
			++j;
		}else
		j=next[j];
	}
	delete []next;

	if(j==t.len)
		return i-t.len+1;
	else
		return 0;
}


#define INFEASIBLE -1//参数不合法
#define OK 1
#define ERROR 0 
#define OVERFLOW -2
typedef string ElemType;
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





void fun(){

	Stack s;
	InitStack(s);
	char c;
	scanf("%c",&c);
	string a,b;
	while(c!='\n'){
		if(isalpha(c)){
			Push(s,string(c));
			//printf("%c\n",c );
		}else{
			//printf("%c\n", c);
			b=Pop(s);
            a=Pop(s);
            Push(s,string(c)+a+b);
            //(string(c)+a+b).print();
		}
		scanf("%c",&c);
	}
	Pop(s).print();
}
int main(){
	fun();
	return 0;
}