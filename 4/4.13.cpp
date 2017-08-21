#include"4.10-4.14.cpp"
int fun4_13(StringType &s,const StringType &t){
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
		len=t.len;
		for(int tmp=pos;tmp+len<s.len;tmp++)
		s.data[tmp]=s.data[tmp+len];
		/////////////////////////////////////////
		s.len-=len;
		s.data=(char*)realloc(s.data,sizeof(char)*s.len);
		n++;
		i=i-t.len;
		//printf("%d\n", i);
    	j=0;
	}else{
		break;
	}
}

return n;
}


int main(){

	StringType s,t;
	InitString(s);
	InitString(t);

	StrAssign(s,"lovelovelucy");
	StrAssign(t,"love");
	fun4_13(s,t);
	show(s);



	return 0;
}