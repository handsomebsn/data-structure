#ifndef __LSTACK__
#define __LSTACK__
#include "all.h"
typedef struct SNode
{
	ElemType data;
	struct SNode *next;
}SNode,*ptrNode;
typedef struct
{
	ptrNode top;
	int len;
}Stack;
Status InitStack(Stack &S);
Status DestoryStack(Stack &S);
Status ClearStack(Stack &S);
Status StackEmpty(Stack S);
int StackLength(Stack S);
Status GetTop(Stack S,ElemType &e);
Status Push(Stack &S,ElemType e);
Status Pop(Stack &S,ElemType &e);
Status StackTraverse(Stack S,Status (*visit)(ElemType));
#endif