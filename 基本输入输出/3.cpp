#include<iostream>
#include<string>
using namespace std;
/*getline  不忽略前导界限符 遇到界限符结束 并不保留界限符在输入队列中--默认界限符号为换行符

cin scanf getline都自动在结尾添加上'\0'
*/
int main(int argc, char const *argv[])
{
	/* c风格字符串之getline*/
	char sex[100];
	char name[100];
	cin>>sex;
	cin.get();//读取保留的换行符
	cin.getline(name,100);
	

	/*string风格字符串之getline*/
	string aihao;
	getline(cin,aihao);
	cout<<endl<<endl;
	cout<<name<<endl;
	cout<<sex<<endl;
	cout<<aihao<<endl;
	return 0;
}
