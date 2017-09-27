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
	
}*GList,Node,*ptrNode;
void sever(string &sub,string &hsub);
Status CreateGList(GList &L,string S);
Status CreateGList(GList &L,string S){
	if(S=="( )")L=NULL;
	else{
		L=new Node;
		if(S.size()==1)
			{L->tag=_ATOM;L->e=S[0];}
		else{
			L->tag=_LISTS;ptrNode p=L,q;
			S=string(&S[0],&S[S.size()-1]);
			string hsub;
			do{	
				sever(S,hsub);
				CreateGList(p->ptr.hp,hsub);q=p;
				if(S!=string()){
					p=new Node;
					p->tag=_LISTS;
					q->ptr.tp=p;
				}

			}while(S!=string());
			q->ptr.hp=NULL;
		}
	}
	return OK;

}



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
	GList glist;
	CreateGList(glist,"(a,b,c,(d,e,f),g,h)");
	return 0;
}