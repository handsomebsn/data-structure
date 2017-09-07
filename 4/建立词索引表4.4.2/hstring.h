#ifndef __HSTRING__
#define __HSTRING__
#include"all.h"
typedef struct HString
{
	char *ch;
	int length;
	HString(){
		ch=NULL;
	}

}HString;
Status StrAssign(HString &T,const char *chars);
int Strlength(const HString &S);
int StrCompare(const HString &S,const HString &T);
Status ClearString(HString &S);
Status Concat(HString &T,const HString &S1,const HString &S2);
Status SubString(HString &sub,const HString &S,int pos,int len);
void ShowString(const HString &S);
#endif