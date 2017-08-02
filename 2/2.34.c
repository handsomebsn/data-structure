#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#define LIST_INT_SIZE 100
#define LISTINCREMENT 10
#define INFEASIBLE -1//参数不合法
#define OK 1
#define ERROR 0
typedef int ElemType;
typedef int Status;//函数状态
typedef	struct	XorNode {
		ElemType data;
		struct	XorNode *LRPtr;
} XorNode, *XorPointer;
typedef	struct {		//无头结点的异或指针双向链表
		XorPointer	Left, Right;		//分别指向链表的左侧和右端
} XorLinkedList;
XorPointer XorP(XorPointer p, XorPointer q);
// 指针异或函数XorP返回指针p和q的异或值


XorPointer XorP(XorPointer p,XorPointer q){
	unsigned long i,j,k;
	i=(unsigned long)p;
	j=(unsigned long)q;
	k=i xor j;
	return (XorPointer)k;

}


XorLinkedList create(){
	XorLinkedList list;
	list.Left=NULL;
	list.Right=NULL;
	return list;
}


void print(XorLinkedList list){
 XorPointer p=list.Left,prior=NULL,tmp;
 //printf("%d \n", p);
 while(p){
 	printf("%d ", p->data);
 	tmp=prior;
 	prior=p;
 	//p=XorP(prior,p->LRPtr);
 	p=XorP(tmp,p->LRPtr);
 	//printf("%d \n", p);
 }


}
Status insert(XorLinkedList &list,int i,ElemType x){
	 XorPointer p=list.Left,prior=NULL,tmp;int k=1;
	 XorPointer newptr,nextptr,nextnextptr;
	 if(i==1&&!list.Left){
	 	newptr=(XorPointer)malloc(sizeof(XorNode));newptr->data=x;
        newptr->LRPtr=NULL;
        list.Left=newptr;
        list.Right=newptr;
        return OK;
	 }


	 if(i==1){
	 	newptr=(XorPointer)malloc(sizeof(XorNode));newptr->data=x;
	 	p->LRPtr=XorP(newptr,p->LRPtr);//NULL XOR A=A
        newptr->LRPtr=p;
        list.Left=newptr;
        return OK;
	 }

 	while(p&&k<i-1){
 		//printf("%c ", p->data);
 		tmp=prior;
 		prior=p;
 		//p=XorP(prior,p->LRPtr);
 		p=XorP(tmp,p->LRPtr);
 		k++;
 	}
 	if(!p)return INFEASIBLE;
 	nextptr=XorP(prior,p->LRPtr);
 	newptr=(XorPointer)malloc(sizeof(XorNode));newptr->data=x;
 	newptr->LRPtr=XorP(p,nextptr);
 	if(nextptr){
 	nextnextptr=XorP(p,nextptr->LRPtr);
 	nextptr->LRPtr=XorP(newptr,nextnextptr);
 	}else{

 		list.Right=newptr;
 	}
 	p->LRPtr=XorP(prior,newptr);
 	return OK;

}
int main(){
XorLinkedList list=create();
insert(list,1,8);
insert(list,1,2);
insert(list,4,3);
print(list);

	return 0;
}