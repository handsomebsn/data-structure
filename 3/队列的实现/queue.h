#ifndef __LQUEUE__
#define __LQUEUE__
#include "all.h"
typedef struct QNode
{
	ElemType data;
	struct QNode *next;
}QNode,*QueuePtr;
typedef struct 
{
	QueuePtr front;
	QueuePtr rear;
	int len;
}LinkQueue;
Status InitQueue(LinkQueue &Q);
Status DestroyQueue(LinkQueue &Q);
Status ClearQueue(LinkQueue &Q);
int Queuelength(LinkQueue &Q);
Status EnQueue(LinkQueue &Q,ElemType e);
Status DeQueue(LinkQueue &Q,ElemType &e);
Status QueueTraverse(LinkQueue Q,void *(visit)(ElemType));
#endif