#include"all.h"
#include <iostream>
#include<string>
using std::string;
typedef enum {_ATOM,_LISTS}Tag;
typedef char ElemType;
typedef struct Node
{	Tag tag;
	union{
		ElemType e;
		struct{struct Node *hp,*tp; }ptr;
	};
	
}*GList;
void sever(string &sub,string &hsub);
Status CreateGList(GList &L,string S);




void sever(string &sub,string &hsub){
	int len=sub.size();
	int k=0,i=0;
	while(i<len&&(sub[i]!=','||k!=0)){
		if(sub[i]=='(')++k;
		else if(sub[i]==')')--k;
		else
			;
		++i;
	}
	if(i<len)
		{hsub=string(&sub[0],&sub[i]);
		sub=string(&sub[i+1],len-i-1);
		}
	else
		{hsub=sub;sub=string();}

}


int main(int argc, char const *argv[])
{
	/* code */
	string sub="a,b,c,(d,e,f),g,h";
	string hsub;
	while(sub!=string()){

		sever(sub,hsub);
		std::cout<<hsub<<std::endl;
	}

	return 0;
}