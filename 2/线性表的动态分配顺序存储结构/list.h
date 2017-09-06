#ifndef __LSQLIST__
#define __LSQLIST__ 
#include "all.h"
#define LIST_INT_SIZE 100
#define LISTINCREMENT 10

typedef struct
{
	ElemType *elem;
	int length;
	int listsize;
}SqList;
Status InitList_Sq(SqList &L);
Status ListInsert_Sq(SqList &L,int i,ElemType e);
Status ListDelete_Sq(SqList &L);
int LocateElem_Sq(SqList L,ElemType e,Status (*compare)(ElemType,ElemType));
void MergeList_Sq(SqList La,SqList Lb,SqList &Lc);
#endif







