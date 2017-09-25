#include<iostream>
using namespace std;
/*cin 忽略前导空白 遇到空白结束 并将空白保留在输入队列中(输入缓存中)*/
int main(int argc, char const *argv[])
{
	/* code */
	char name[100];
	char sex[100];
	cin>>name>>sex;
	cout<<name<<endl;
	cout<<sex<<endl;
	return 0;
}