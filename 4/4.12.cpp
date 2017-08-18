#include "4.10-4.14.cpp"
int fun4_12(StringType &s,const StringType &t,const StringType &v){
	int n=0;
	int i=0,j=0;
	int *next=(int*)malloc(sizeof(int)*t.len);
	next[0]=-1;j=-1;
	while(i<t.len){
		if(j==-1||t.data[i]==t.data[j])
		{
			++i;
			++j;
			next[i]=j;
		}else
		j=next[j];

	}

    i=0;j=0;
    int pos;
    int len;
    while(true){
    	
	while(i<s.len&&j<t.len){
		if(j==-1||s.data[i]==t.data[j])
		{
			++i;
			++j;
		}else
		j=next[j];
	}
	if(j==t.len){
		pos=i-t.len;
		if(v.len<t.len){
			len=t.len-v.len;
			//
			for(int tmp1=pos;tmp1+len<s.len;tmp1++)
				s.data[tmp1]=s.data[tmp1+len];
			s.len-=len;
			s.data=(char*)realloc(s.data,sizeof(char)*s.len);
		}else{
			len=v.len-t.len;
			s.len+=len;
			s.data=(char*)realloc(s.data,sizeof(char)*s.len);
			for(int tmp2=s.len-1;tmp2-len>=pos;tmp2--)
				s.data[tmp2]=s.data[tmp2-len];
		}
		for(int tmp=0;tmp<v.len;tmp++,pos++)
			s.data[pos]=v.data[tmp];
		/////////////////////////////////////////
		n++;
		i=i+v.len-t.len;
		//printf("%d\n", i);
    	j=0;
	}else{
		break;
	}
}

return n;
}


int main(){

	StringType s,t,v;
	InitString(s);
	InitString(t);
	InitString(v);
	StrAssign(s,"i love love lucy");
	StrAssign(t,"love");
	StrAssign(v,"lll");
	fun4_12(s,t,v);
	show(s);



	return 0;
}