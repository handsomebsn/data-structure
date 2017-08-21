#include<stdio.h>
#include<string.h>
#define INFEASIBLE -1//参数不合法
#define OVERFLOW -2
#define OK 1
#define ERROR 0
typedef int Status;//函数状态
#define MAXSTRLEN 255
typedef unsigned char SString[MAXSTRLEN+1];
Status StrAssign(SString &T,const char *s){
	int slen=strlen(s);
	int i=1;
	if(slen>MAXSTRLEN){
		for(i=1;i<=MAXSTRLEN;i++)
			T[i]=s[i-1];
		T[0]=MAXSTRLEN;
		return ERROR;
	}else{
		for(i=1;i<=slen;i++)
			T[i]=s[i-1];
		T[0]=slen;
		return OK;
	}

}
void show(SString s){
	for(int i=1;i<=s[0];i++)
		printf("%c",s[i]);
}
int main(){
	

	return 0;
}

