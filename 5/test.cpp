#include<stdio.h>
struct test
{
	char data[5];
	int x;
	
};
int main(){
	test a,b;
	b.data[0]='a';
	b.data[1]='b';
	b.data[2]='c';
	b.data[3]=0;
	a=b;
	printf("%p\n", a.data);
	printf("%p\n",b.data );
	printf("%s\n",a.data);
	int aa[5];
	int bb[5];
	//aa=bb;


	return 0;
}