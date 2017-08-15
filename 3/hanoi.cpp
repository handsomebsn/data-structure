#include<stdio.h>
#include<stdlib.h>

void move(char a,int i,char b){
	printf("move %d form %c to %c\n",i,a,b );
}

void hanoi(int n,char x,char y,char z){
	if(n==1)
		move(x,1,z);
	else{
		hanoi(n-1,x,z,y);
		move(x,n,z);
		hanoi(n-1,y,x,z);
	}
}


int main(int argc, char const *argv[])
{
	/* code */
	hanoi(4,'X','Y','Z');
	return 0;
}