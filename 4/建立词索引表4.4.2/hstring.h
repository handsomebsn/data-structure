#ifndef __HSTRING__
#define __HSTRING__
#include"all.h"
typedef struct 
{
	char *ch;
	int length;
	
}HString;
Status StrAssign(HString &T,char *chars);
int Strlength(const HString &S);
int StrCompare(const HString &S,const HString &T);
Status ClearString(HString &S);
Status Concat(HString &T,const HString &S1,const HString &S2);
Status SubString(HString &sub,const HString &S,int pos,int len);
#endif