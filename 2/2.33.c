#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#define LIST_INT_SIZE 100
#define LISTINCREMENT 10
#define INFEASIBLE -1//参数不合法
#define OK 1
#define ERROR 0
typedef char ElemType;
typedef int Status;//函数状态
typedef struct LNode{
  ElemType data;
  struct LNode *next;
}LNode,*LinkList;//线性链表类型
//创建带头结点的单链表
LinkList createLinkList(){
  LinkList head=(LinkList)malloc(sizeof(LNode));
  head->next=NULL;
  return head;
}
//创建带头结点的单循环链表
LinkList createclLinkList(){
  LinkList head=(LinkList)malloc(sizeof(LNode));
  head->next=head;
  return head;
}

//用尾插法插入单链表
void insertend(LinkList list){
  LinkList rear=list,newptr=NULL;
  while(rear->next)rear=rear->next;
  int n;
  printf("press n\n");

  scanf("%d",&n);
  setbuf(stdin, NULL);//清空输入缓存
  char c;
  for(int i=0;i<n;i++){
  	scanf("%c",&c);
  	newptr=(LinkList)malloc(sizeof(LNode));
  	newptr->data=c;
  	newptr->next=NULL;
  	rear->next=newptr;
  	rear=newptr;
  }


}

void print(LinkList l){
	l=l->next;
	if(!l)return;
	while(l->next){
		printf("%c ",l->data);
		l=l->next;
	}
	printf("%c\n",l->data);
}

void printcl(LinkList list){
	if(!list)return;
	LinkList p=list->next;
	if(p==list)return;
	while(p!=list){
		printf("%c ",p->data);
		p=p->next;
	}
	printf("\n");
}

Status fun3_33(LinkList list,LinkList cla,LinkList clb,LinkList clc){
	if(!list)return ERROR;
	LinkList pre=list,p=pre->next;
	while(p){
        pre->next=p->next;
        if(isalpha(p->data)){
        	p->next=cla->next;
        	cla->next=p;
        }else if(isdigit(p->data)){
        	p->next=clb->next;
        	clb->next=p;
        }else{
        	p->next=clc->next;
        	clc->next=p;
        }
		p=pre->next;
	}
list->next=NULL;

}
int main(){
   LinkList list=createLinkList();
   LinkList cla=createclLinkList();
   LinkList clb=createclLinkList();
   LinkList clc=createclLinkList();
   insertend(list);
   print(list);
  	fun3_33(list,cla,clb,clc);
  	printcl(cla);
  	printcl(clb);
  	printcl(clc);
	return 0;
}