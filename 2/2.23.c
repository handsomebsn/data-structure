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
ListMerge(lista,listb,listc);
printf("after ListMerge(lista,listb,listc)\n" );
print(listc);
  return 0;
}