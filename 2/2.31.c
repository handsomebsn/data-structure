#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define LIST_INT_SIZE 100
#define LISTINCREMENT 10
#define INFEASIBLE -1//参数不合法
#define OVERFLOW -2
#define OK 1
#define ERROR 0
typedef int ElemType;
typedef int Status;//函数状态
typedef struct LNode{
  ElemType data;
  struct LNode *next;
}LNode,*LinkList;//线性链表类型



Status insert(LinkList &list,int i,ElemType x){
	//if(!list&&i>1)return INFEASIBLE;
	if(i<1)return INFEASIBLE;
	if(!list&&i==1){
		list=(LinkList)malloc(sizeof(LNode));
		if(!list)return OVERFLOW;
		list->data=x;
		list->next=list;
		return OK;
	}
	LinkList pre=list,newptr=NULL,p=list;
	int count=1;
	while(pre->next!=list){pre=pre->next;count++;}
	if(i>count+1)return INFEASIBLE;
	int k=1;
	if(i==1){
		newptr=(LinkList)malloc(sizeof(LNode));
		newptr->data=x;
		newptr->next=list;
		list=newptr;
		pre->next=newptr;
	}else{
		while(k<i){pre=p; p=p->next;k++;}
			newptr=(LinkList)malloc(sizeof(LNode));
		newptr->data=x;
		newptr->next=pre->next;
		pre->next=newptr;
	}




}


Status fun2_31(LinkList s){
	if(s==s->next) return ERROR;
	LinkList p=s;
	while(p->next->next!=s){
		p=p->next;
	}
	free(p->next);
	p->next=s;

}


