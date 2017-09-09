#include <stdio.h>
typedef struct Node
{
	int z;
	struct 
	{
		int x;
		int y;	
	};

}Node;
int main(){
	Node test;
	test.x=1;
	test.y=2;
	test.z=3;
	printf("%d\n", test.z);

	return 0;
}