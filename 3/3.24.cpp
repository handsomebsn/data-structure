#include<stdio.h>
#include<stdlib.h>
int g(int m,int n){
	if(m<0||n<0)exit(-1);
	if(m==0)return 0;
	return g(m-1,2*n)+n;
}
int main(int argc, char const *argv[])
{
	/* code */
	printf("%d\n",g(-5,2) );
	return 0;
}