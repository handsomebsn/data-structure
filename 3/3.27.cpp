#include<stdio.h>
#include<stdlib.h>
int akm(int m,int n){
	if(m<0||n<0)exit(-1);
	if(m==0)return n+1;
	else if(m!=0&&n==0)
		return akm(m-1,1);
	else if(m!=0&&n!=0)
	return akm(m-1,akm(m,n-1)); 
}
int main(int argc, char const *argv[])
{
	/* code */
	printf("%d\n",akm(1,2) );
	return 0;
}