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




int Strlength(const HString &S){

	return S.length;
}


int StrCompare(const HString &S,const HString &T){
	int minlen=S.length<T.length?S.length:T.length;
	for(int i=0;i<minlen;i++){
		if(S.ch[i]!=T.ch[i])
			return S.ch[i]-T.ch[i];
	}
	return S.length-T.length;
}

Status ClearString(HString &S){
	if(S.ch){free(S.ch);S.ch=NULL;}
	S.length=0;
}


Status Concat(HString &T,const HString &S1,const HString &S2){
	if(T.ch)free(T.ch);
	T.length=S1.length+S2.length;
	if(!T.length){T.ch=NULL;return OK;}
	T.ch=(char*)malloc(sizeof(char)*T.length);
	if(!T.ch)return OVERFLOW;
	int i=0;
	for(;i<S1.length;++i)
		T.ch[i]=S1.ch[i];
	for(int j=0;j<S2.length;++j,++i)
		T.ch[i]=S2.ch[j];
	return OK;
}

Status SubString(HString &sub,const HString &S,int pos,int len){
	if(pos<1||pos>S.length||len<0||pos+len-1>S.length)
		return OVERFLOW;
	if(sub.ch)free(sub.ch);
	sub.length=len;
	sub.ch=(char*)malloc(sizeof(char)*sub.length);
	int si=pos-1;
	for(int i=0;i<len;++i,++si)
		sub.ch[i]=S.ch[si];
	return OK;
}