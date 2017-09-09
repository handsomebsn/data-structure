#include<stdio.h>
#include "array.h"
int main(int argc, char const *argv[])
{
	/* code */
	Array a;
	InitArray(a,2,5,5);
	Assign(a,998,1,1);
	int e;
	Value(a,e,1,1);
	printf("%d\n",e);


	return 0;
}