
#include<stdio.h>
#include<string.h>
class string{
	private:
		char *str;
		int len;
		//const int initsize;
	public:
		string();
		string(const char _str[]);
		string(const string &s);
		~string(){printf("delete %s\n",str );delete [] str;strnumber--;}
	static const int initsize;
	static int strnumber;
	static int number(){return strnumber;}
	/////////////////////////////////
	int length()const; 
	const char * c_str(){return str;}
	void print();
	///////////////////////////////////
	string& operator =(const string &s);
	string operator+(const string &s);
	////////////////////////////////////
	operator const char*(){return str;};
	////
	string sssss(){string tmp("tmp");return tmp;}
	void bbbbb(){str[0]='B';str[1]='\0';};

};
/*string::string():initsize(4){


}*/
const int string::initsize=4;
int string::strnumber=0;

string::string(){
	str=new char[1];
	if(!str)throw("OVERFLOW");
	str[0]='\0';
	len=0;
	//
	strnumber++;
}
string::string(const char _str[]){
	len=strlen(_str);
	str=new char[len+1];
	strcpy(str,_str);

	strnumber++;
}

string::string(const string &s){
	len=s.length();
	str=new char[len+1];
	strcpy(str,s.str);
	printf("fuzhigouzaohanshu\n");
}

string& string::operator=(const string &s){
	len=s.length();
	str=new char[len+1];
	strcpy(str,s.str);
	printf("--============--\n");
	return *this;
}
string string::operator+(const string &s){
	string newstr;
	char *tmp=newstr.str;
	/////////////////////////////////////
	newstr.len=length()+s.length();
 	newstr.str=new char[newstr.len+1];
 	strcpy(newstr.str,str);
    strcat(newstr.str,s.str);
    delete[]tmp;
	return newstr;
}

int string::length()const{
 return len;
}

void string::print(){
	printf("%s\n", str);
}



int main(){
	string a("A");
	//string c;
	a.sssss();
	string b =a.sssss();
	b.bbbbb();
	string c("C");


	return 0;
}