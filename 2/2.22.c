#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define LIST_INT_SIZE 100
#define LISTINCREMENT 10
#define ERROR 0
#define INFEASIBLE -1//参数不合法
#define VOERFLOW -2
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

void Deletemintomax(LinkList list,ElemType mink,ElemType maxk){
  LinkList pre=list,p=list->next,q=NULL,tmp=NULL;
  while(p&&p->data<=mink){pre=p;p=p->next;}
  if(!p)return ;
  q=p;
  while(q&&q->data<maxk){tmp=q;q=q->next;free(tmp);}
  pre->next=q;

}

void Deletext(LinkList list){
  LinkList pre=list,p=list->next,tmp=NULL;
 while(p){
  if(pre!=list&&pre->data==p->data)
  {pre->next=p->next;tmp=p;p=p->next;free(tmp);}
  else 
     {pre=p;p=p->next;}

 }
}


// 带头结点的单链表的逆置
Status ListOppose(LinkList list){
	if(!list)return ERROR;
	LinkList p=list->next;LinkList tmp=NULL;
	if(!p||(p&&!p->next))return ERROR;
		LinkList q=p->next;
   p->next=NULL;
   while(q){
   	tmp=q->next;
   	q->next=p;
   	p=q;
   	q=tmp;
   }
   list->next=p;
}



int main(){
  srand(time(NULL));
  LinkList list=createLinklist();
  for(int i=0;i<5;i++)
  {
    InsertUp(list,rand()%10);
  }
print(list);
ListOppose(list);
printf("after ListOppose(list)\n" );
print(list);
  return 0;
}