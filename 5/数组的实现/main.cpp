#include<stdio.h>
int main(int argc, char const *argv[])
{
	/* code */
	int a=9;
	int *p=&a;
	printf("%p\n",p );
	p=p+2;
	printf("%p\n",p );
	return 0;
}