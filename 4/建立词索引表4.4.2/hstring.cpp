#include "hstring.h"
Status StrAssign(HString &T,char *chars){
	if(T.ch)free(T.ch);
	int len=0;
	for(;*chars;++len,++chars) ;
    if(!len){T.ch=NULL;T.length=0;}
	else{
		if(!(T.ch=(char*)malloc(sizeof(char)*len)));
		return OVERFLOW;
		for(int i=0;i<len;i++)
			T.ch[i]=chars[i];
		T.length=len;
	}
	return OK;
}