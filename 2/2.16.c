#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define LIST_INT_SIZE 100
#define LISTINCREMENT 10
#define INFEASIBLE -1//参数不合法
#define OK 1
typedef int ElemType;
typedef int Status;//函数状态
typedef struct LNode{
  ElemType data;
  struct LNode *next;
}LNode,*LinkList;//线性链表类型

//无头结点的单链表
Status insert(LinkList &list,int i,ElemType x){
	LinkList pre=list,newptrnode;
	int k=2;
	if(!list&&i>1) return -999;
	if(i==1){
    	newptrnode=(LinkList)malloc(sizeof(LNode));
    	newptrnode->data=x;
    	newptrnode->next=list;
    	list=newptrnode;
	}else{
		//if(pre) printf("afdfddfsdfs\n");
		while(k<i&&pre->next){ pre=pre->next;i++;}
		if(k<i&&!pre->next) return INFEASIBLE;
		newptrnode=(LinkList)malloc(sizeof(LNode));
    	newptrnode->data=x;
		   newptrnode->next=pre->next;
          pre->next=newptrnode;
	}
	return OK;
}
//
Status Delete(LinkList list,int i){



}
int main(){

LinkList list=NULL;
if(list==NULL)
printf("%d\n",list);
Status stat;
stat =insert(list,1,3);
printf("%d\n",stat);
stat =insert(list,1,8);
printf("%d\n",stat);
stat =insert(list,3,8);
printf("%d\n",stat);

	return 0;
}