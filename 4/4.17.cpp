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
int StrCompare(const SString &s,const SString &t){
	int minlen=s[0]<t[0]?s[0]:t[0];
	for(int i=1;i<=minlen;i++){
		if(s[i]!=t[i])
			return s[i]-t[i];
	}
	return s[0]-t[0];
}

Status  SubString(SString s,int start,int len,SString v){
	if(start+len-1>len)return ERROR;
	v[0]=len;
	for(int i=start,j=1;i<=len;i++,j++)
		v[j]=s[start];
	return OK;
}

Status Replace(SString &s,const SString t, const SString v)
{
	int i=1;
	for(;i<=MAXSTRLEN;i++)
		;

}

int main(){
    SString s,t;
    StrAssign(s,"abcd");
    StrAssign(t,"abca");
    printf("%d\n", StrCompare(s,t));


	return 0;
}