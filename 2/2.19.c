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

void Deletemintomax(LinkList list,ElemType mink,ElemType maxk){
  LinkList pre=list,p=list->next,q=NULL,tmp=NULL;
  while(p&&p->data<=mink){pre=p;p=p->next;}
  if(!p)return ;
  q=p;
  while(q&&q->data<maxk){tmp=q;q=q->next;free(tmp);}
  pre->next=q;

}

int main(){
  srand(time(NULL));
  LinkList list=createLinklist();
  for(int i=0;i<20;i++)
  {
    InsertUp(list,rand()%100);
  }
print(list);
ElemType mink,maxk;
printf("please enter mink maxk\n");
scanf("%d%d",&mink,&maxk);
Deletemintomax(list,mink,maxk);
printf("after Deletemintomax(list,%d,%d)\n",mink,maxk );
print(list);
  return 0;
}