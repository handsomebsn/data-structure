
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
		~string(){delete [] str;strnumber--;}
	static const int initsize;
	static int strnumber;
	static int number(){return strnumber;}
	/////////////////////////////////
	int length()const; 
	const char * c_str(){return str;}
	void print();
	int kmp(const string &t)const;
	///////////////////////////////////
	string& operator =(const string &s);
	string operator+(const string &s);
	////////////////////////////////////
	operator const char*(){return str;};
	

};
/*string::string():initsize(4){


}*/
const int string::initsize=4;
int string::strnumber=0;

string::string(){
	//printf("gouzao\n");
	str=new char[1];
	if(!str)throw("OVERFLOW");
	str[0]='\0';
	len=0;
	//
	strnumber++;
}
string::string(const char _str[]){
	//printf("gouzao\n");
	len=strlen(_str);
	str=new char[len+1];
	strcpy(str,_str);

	strnumber++;
}

string::string(const string &s){
	len=s.length();
	str=new char[len+1];
	strcpy(str,s.str);
	//printf("fuzhigouzaohanshu\n");
}

string& string::operator=(const string &s){
	len=s.length();
	str=new char[len+1];
	strcpy(str,s.str);
	//printf("--============--\n");
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


int string::kmp(const string &t)const{
	int i=0;
	int j=0;
	/////////////////////
	int *next=new int[t.len];
	next[0]=-1;j=-1;
	while(i<t.len){
		if(j==-1||t.str[i]==t.str[j]){
			++i;
			++j;
			next[i]=j;
		}else
		j=next[j];
	}
	///////////////////////
    i=0;j=0;
	while(i<len&&j<t.len){
		if(j==-1||str[i]==t.str[j])
		{
			++i;
			++j;
		}else
		j=next[j];
	}
	delete []next;

	if(j==t.len)
		return i-t.len+1;
	else
		return 0;
}


int main(){
   string a("abchello");
   string b("allo");
   printf("%d\n", a.kmp(b));




	return 0;
}