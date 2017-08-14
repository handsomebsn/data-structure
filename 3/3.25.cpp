#include<stdio.h>
#include<stdlib.h>
int F(int n){
	if(n<0)exit(-1);
	if(n==0)return 1;
	return n*F(n/2);
}
int F1(int n){
	int s=1;
	int a[n+1]={0};
	a[0]=1;
	for(int i=1;i<=n;i++){
		a[i]=i*a[i/2];
	}
	return a[n];
}
int main(int argc, char const *argv[])
{
	/* code */
	printf("%d\n",F1(9) );
	return 0;
}