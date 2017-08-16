
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
ElemType GetTop(const Stack &S){

    if(S.top==0){printf("Stack is empty\n");exit(-1);};
    return S.data[S.top-1];
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

//////////////////////////////////////////////////////////////////


/*判断输入的某个字符是否是算符 
 *c表示输入的字符 
 *op数组中存放系统能识别的算符 
 */  
Status In(char c){
    static const char op[]={'+','-','*','/','(',')','#','\0'};  
    int i=0;
    while(op[i]!='\0'){
        if(c==op[i])return true;
        i++;
    }
    return false;  
}  



/*比较两个算符的优先级 
 *a，b中存放待比较的算符  运算符和界限符统称为算符
 *'>'表示a>b 
 *'0'表示不可能出现的比较 
 */  
char Precede(char a, char b){  
    int i,j;  
    static const char pre[][7]={           
    /*运算符之间的优先级制作成一张表格*/  
        {'>','>','<','<','<','>','>'},  
        {'>','>','<','<','<','>','>'},  
        {'>','>','>','>','<','>','>'},  
        {'>','>','>','>','<','>','>'},  
        {'<','<','<','<','<','=','0'},  
        {'>','>','>','>','0','>','>'},  
        {'<','<','<','<','<','0','='}};  
    switch(a){  
        case '+': i=0; break;  
        case '-': i=1; break;  
        case '*': i=2; break;  
        case '/': i=3; break;  
        case '(': i=4; break;  
        case ')': i=5; break;  
        case '#': i=6; break;  
    }  
    switch(b){  
        case '+': j=0; break;  
        case '-': j=1; break;  
        case '*': j=2; break;  
        case '/': j=3; break;  
        case '(': j=4; break;  
        case ')': j=5; break;  
        case '#': j=6; break;  
    }  
    return pre[i][j];  
}  



/*进行实际的运算 
 *a，b中分别以整数的形式存放两个待运算的操作数 
 *theta中存放代表操作符的字符 
 *结果以整数的形式返回 
 */  
ElemType Operate(ElemType a, char theta, ElemType b){  
    ElemType result;  
  
    switch(theta)   {  
        case '+': result = a + b; break;  
        case '-': result = a - b; break;  
        case '*': result = a * b; break;  
        case '/': result = a / b; break;  
    }  
    return result;  
}  



/*从输入缓冲区中获得下一个整数或运算符，并通过n带回到主调函数 
 *返回值为1表示获得的是运算符 
 *返回值为0表示获得的是整形操作数 
 */  
 ElemType getNext(ElemType &n){  
    char c;  
    n=0;  
    while((c=getchar())==' ');  /*跳过一个或多个空格*/  
    if(In(c)){            /*是算符*/  
        n=c;  //char型转换为ElemType型
        return 1;  
    }  
    while(isdigit(c)){                       
        n=n*10+(c-'0');       /*把连续的数字字符转换成相对应的整数*/  
        c=getchar();  
    }             
    ungetc(c,stdin);            /*新读入的字符不是数字，可能是算符,为了不影响下次读入，把该字符放回到输入缓冲区*/  
    return 0;  
}  

ElemType fun(){
    ElemType c,theta;
    ElemType a,b;
    Stack optr;InitStack(optr);Push(optr,'#');
    Stack opnd;InitStack(opnd);int flag=getNext(c);
    while(c!='#'||GetTop(optr)!='#'){
        if(!flag){Push(opnd,c);flag=getNext(c);}
        else
            switch(Precede((char)GetTop(optr),(char)c)){
                case '0':printf("biaodashi is wrong\n");exit(-1);
                case '<':Push(optr,c);flag=getNext(c);break;
                case '=':Pop(optr);flag=getNext(c);break;
                case '>':Pop(opnd,b);Pop(opnd,a);Pop(optr,theta);
                Push(opnd,Operate(a,(char)theta,b));break;

            }
    }
    ElemType res=GetTop(opnd);
    DestroyStack(optr);
    DestroyStack(opnd);
    return res;

}



int main(){
    printf("%d\n", fun());
    return 0;
}
