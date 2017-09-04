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
Status Concat(HString &T,HString S1,HString S2);
HString SubString(const HString &S,int pos,int len);
#endif