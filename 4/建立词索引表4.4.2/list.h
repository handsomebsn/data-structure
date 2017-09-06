#ifndef __LLIST__
#define __LLIST__
#include "all.h"
typedef int ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}*Link,*Position;
typedef struct 
{
	Link head,tail;
	int len;
}LinkList;
#endif