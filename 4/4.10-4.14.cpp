#include<stdio.h>
#include<malloc.h>
#include<string.h>
typedef int Status;
#define INFEASIBLE -1//参数不合法
#define OK 1
#define ERROR 0 
#define OVERFLOW -2
typedef struct{
	char *data;
	int len;
}StringType;
Status InitString(StringType &s){
	s.data=(char*)malloc(sizeof(char)*4);
	s.len=4;
}
void StrAssign(StringType &t,const char *s){
	if(t.data)free(t.data);
	t.len=strlen(s);
	t.data=(char*)malloc(sizeof(char)*t.len);
	for(int i=0;i<t.len;i++)
		t.data[i]=s[i];
}
int StrCompare(const StringType &s,const StringType &t){
	int i=0;
	while(i<s.len&&i<t.len){
		if(s.data[i]!=t.data[i])return s.data[i]-t.data[i];
			i++;
	}
	return s.len-t.len;

}
int Strlength(const StringType &s){

	return s.len;
}

void show(const StringType &s){
	for(int i=0;i<s.len;i++)
	printf("%c",s.data[i]);
}
StringType Concat(const StringType &s,const StringType &t){
	StringType con;
	con.len=s.len+t.len;
	con.data=(char*)malloc(sizeof(char)*con.len);
	int i=0;
	for(;i<s.len;i++)
		con.data[i]=s.data[i];
	for(int j=0;j<t.len;j++,i++)
		con.data[i]=t.data[j];
	return con;
}
StringType SubString(StringType s,int start,int len){
  StringType tmp;
  tmp.len=len;
  tmp.data=(char*)malloc(sizeof(char)*tmp.len);
  for(int i=0;i<tmp.len;i++,start++)
  	tmp.data[i]=s.data[start-1];
  return tmp;
}
/*
int main(){
	StringType t1,t2;
	InitString(t1);
	InitString(t2);
	StrAssign(t1,"hello ");
	StrAssign(t2,"world");
	StringType t3= Concat(t1,t2);
	show(t3);
	printf("\n");
	StringType t4=SubString(t1,3,3);
	show(t4);
	printf("\n");
	
	

	return 0;
}
*/