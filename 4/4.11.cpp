#include "4.10-4.14.cpp"
int Index(const StringType &s,char x){
	int i=0;
	for(;i<s.len&&x!=s.data[i];i++)
		;
	if(i==s.len)
		return 0;
	else
		return i+1;


}

StringType fun4_11(const StringType &s,const StringType &t){
	StringType r;
	r.data=(char*)malloc(sizeof(char)*s.len);
	r.len=0;
	for(int i=0;i<s.len;i++){
		if(!Index(t,s.data[i]))
			if(!Index(r,s.data[i]))
				 r.data[r.len++]=s.data[i];  
	}
	return r;
}
int main(){
	StringType s,t;
	InitString(s);
	InitString(t);
	StrAssign(s,"hello");
	StrAssign(t,"l");
	StringType r=fun4_11(s,t);
	show(r);
	printf("\n");

	return 0;
}