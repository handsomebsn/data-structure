#include "4.10-4.14.cpp"
void fun4_10(StringType &s){
	char tmp;
	int k=s.len/2;
	int m=s.len-1;
	for(int i=0;i<k;i++)
	{
		tmp=s.data[i];
		s.data[i]=s.data[m-i];
		s.data[m-i]=tmp;
	}
}
int main(){
	StringType s;
	InitString(s);
	StrAssign(s,"I Love You");
	show(s);
	printf("\n");
	fun4_10(s);
	show(s);
	printf("\n");
	return 0;
}
