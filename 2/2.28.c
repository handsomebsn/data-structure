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
//创建带头结点的链表
LinkList createLinklist(){
  LinkList head=(LinkList)malloc(sizeof(LNode));
  head->next=NULL;
  return head;
}
//
void InsertUp(LinkList list,ElemType x){
  LinkList pre=list,p=list->next;
  while(p&&x>p->data){pre=p;p=p->next;}
   LinkList newptrnode=(LinkList)malloc(sizeof(LNode));
   newptrnode->data=x;
   newptrnode->next=pre->next;
   pre->next=newptrnode;
}

void print(LinkList list){

  list=list->next;
  int i=1;
  while(list){
    printf("%d %d\n",i,list->data);
    list=list->next;
    i++;
  }

}

void InsertEnd(LinkList list,ElemType x){
	while(list->next){
		list=list->next;
	}
	LinkList newptr=(LinkList)malloc(sizeof(LNode));
	newptr->data=x;
	newptr->next=list->next;
	list->next=newptr;
}




Status ListCross1(LinkList A,LinkList B,LinkList C){
	LinkList pre=A,p=A->next,q=B->next;
	//C->next=A->next;
	while(p&&q){
		if(p->data==q->data)
			{pre=p;p=p->next;q=q->next;}
		else if(p->data<q->data)
			{pre->next=p->next;free(p); p=pre->next;}
		else
			q=q->next;
	}
	C->next=A->next;
}
Status ListCross(LinkList A,LinkList B,LinkList C){
	LinkList pre=A,p=A->next,q=B->next;
	//C->next=A->next;
	while(p&&q){
		if((p->data==q->data&&pre==A)||(p->data==q->data&&pre->data!=p->data))
			{pre=p;p=p->next;q=q->next;}
		else if(p->data<q->data)
			{pre->next=p->next;free(p); p=pre->next;}
		else
			q=q->next;
	}
	pre->next=NULL;
	while(p){
		pre=p; p=p->next;free(pre);
	}
	C->next=A->next;
	A->next=NULL;
}




int main(){
	srand(time(NULL));
LinkList a=createLinklist();
LinkList b=createLinklist();
LinkList c=createLinklist();
for(int i=0;i<20;i++){
	InsertUp(a,rand()%20);
}
print(a);
for(int i=0;i<20;i++){
	InsertUp(b,rand()%20);
}
printf("\n");
print(b);
ListCross(a,b,c);
printf("after ListCross(a,b,c)\n");

 print(c);
    return 0;
}
