#ifndef __LSQLIST__
#define __LSQLIST__ 
#include "all.h"
#define LIST_INT_SIZE 100
#define LISTINCREMENT 10

typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}*Link,*Postion;
typedef struct
{
	Link head,tail;
	int len;
}LinkList;
Status MakeNode(Link &p,ElemType e);
void FreeNode(Link &p);
Status InitList(LinkList &L);
Status DestoryList(LinkList &L);
Status ClearList(LinkList &L);
Status InsFirst(Link h,Link s);
Status DelFirst(Link h,Link &q);
Status Append(LinkList &L,Link s);
Status Remove(LinkList &L,Link &q);
Status InsBefore(LinkList &L,Link &p,Link s);
Status InsAfter(LinkList &L,Link &p,Link s);
Status SetCurElem(Link &p,ElemType e);
ElemType GetCurElem(Link p);
Status ListEmpty(LinkList L);
Postion GetHead(LinkList L);
Postion GetLast(LinkList L);
Postion PriorPos(LinkList L,Link p);
Postion NextPos(LinkList L,Link p);
Status LocatePos(LinkList L,int i,Link &p);
Postion LocateElem(LinkList L,ElemType e,int (*compare)(ElemType,ElemType));
Status ListTraverse(LinkList L,Status (*visit)(ElemType));
Status ListInsert(LinkList &L,int i,ElemType e);
Status MergeList(LinkList &La,LinkList &Lb,LinkList &Lc,int (*compare)(ElemType,ElemType));
#endif







