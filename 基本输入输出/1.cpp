#include<stdio.h>
/*scanf 忽略前导空白 遇到空白结束 并将空白保留在输入队列中(输入缓存中)*/
int main(int argc, char const *argv[])
{
	/* code */
	char name[100];
	char sex[100];
	char c;
	scanf("%s",name);
	scanf("%c",&c);
	scanf("%s",sex);
	printf("%s\n", name);
	printf("C:%chello\n",c );
	printf("%s\n", sex);
	return 0;
}
