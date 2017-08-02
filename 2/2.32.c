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
  struct LNode *prior;
}LNode,*LinkList;//线性链表类型

void fun3_32(LinkList s){
	if(!s)return;
 if(s->next==s)s->prior=s;
LinkList pre=s,p=pre->next;
while(p!=s){ p->prior=pre; pre=p;p=p->next;}
s->prior=pre;

}