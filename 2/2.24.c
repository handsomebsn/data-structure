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
 if(!list)return;
  list=list->next;
  int i=1;
  while(list){
    printf("%d %d\n",i,list->data);
    list=list->next;
    i++;
  }

}

Status ListMerge(LinkList A,LinkList B,LinkList C){
   LinkList p=A->next,q=B->next,tmpanext,tmpbnext;
   C->next=A->next;
   while(p&&q){
    tmpanext=p->next;
    tmpbnext=q->next;
    if(p->next)
    q->next=p->next;
    p->next=q;
      p=tmpanext;
      q=tmpbnext;
   }
    B->next=NULL;
    A->next=NULL;
    return OK;
}
//A,B都为升序的线性表 利用A,B的空间将A,B合并到C中，并使得C表中元素从大到小
Status ListMergeOppose(LinkList A,LinkList B,LinkList C){
  LinkList p=A->next,q=B->next,tmp;
  while(p&&q){
    if(p->data<q->data)//选出A,B中较小的用头插法插入到C表中
    {tmp=p;p=p->next;tmp->next=C->next;C->next=tmp;}
   else
   {tmp=q;q=q->next;tmp->next=C->next;C->next=tmp;}
  }
  while(p){
    tmp=p;p=p->next;tmp->next=C->next;C->next=tmp;
  }
  while(q){
   tmp=q;q=q->next;tmp->next=C->next;C->next=tmp;
  }
A->next=NULL;B->next=NULL;
 return OK;
}

int main(){
  srand(time(NULL));
  LinkList lista=createLinklist();
  LinkList listb=createLinklist();
  LinkList listc=createLinklist();
  for(int i=0;i<rand()%20;i++)
  {
    InsertUp(lista,rand()%10);
  }
  for(int i=0;i<rand()%20;i++)
  {
    InsertUp(listb,rand()%10);
  }
print(lista);
printf("\n");
print(listb);
ListMergeOppose(lista,listb,listc);
printf("after ListMergeOppose(lista,listb,listc)\n" );
print(listc);
  return 0;
}
