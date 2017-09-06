#include "queue.h"
Status InitQueue(LinkQueue &Q){
	Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));
	if(!Q.front)return OVERFLOW;
	Q.front->next=NULL;
	Q.len=0;
	return 0;
}
Status DestroyQueue(LinkQueue &Q){
	QueuePtr p,tmp;
	p=Q.front;
	while(p){
		tmp=p;
		p=p->next;
		free(tmp);
	}
	Q.front=Q.rear=NULL;
	Q.len=0;
	return OK;
}
Status ClearQueue(LinkQueue &Q){
	QueuePtr p,tmp;
	p=Q.front->next;
	while(p){
		tmp=p;
		p=p->next;
		free(tmp);
	}
	Q.rear=Q.front;
	Q.len=0;
	return OK;

}
int Queuelength(LinkQueue &Q){
	return Q.len;
}
Status EnQueue(LinkQueue &Q,ElemType e){
	QueuePtr newnode=(QueuePtr)malloc(sizeof(QNode));
	if(!newnode)return OVERFLOW;
	newnode->data=e;
	newnode->next=NULL;
	Q.rear->next=newnode;
	Q.rear=newnode;
	++Q.len;
	return OK;
}
Status DeQueue(LinkQueue &Q,ElemType &e){
	if(Q.front==Q.rear)return ERROR;
	QueuePtr tmp=Q.front->next;
	e=tmp->data;
	if(tmp==Q.rear)Q.rear=Q.front;
	Q.front->next=tmp->next;
	free(tmp);
	--Q.len;
	return OK;
}
Status QueueTraverse(LinkQueue Q,void *(visit)(ElemType)){
	QueuePtr p;
	p=Q.front->next;
	while(p){
		(*visit)(p->data);
		p=p->next;
	}
	return OK;
}