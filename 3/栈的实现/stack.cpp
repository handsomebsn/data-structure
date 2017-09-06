#include "stack.h"
Status InitStack(Stack &S){
	S.top=(ptrNode)malloc(sizeof(SNode));
	if(!S.top)return ERROR;
	S.top->next=NULL;
    S.len=0;
    return OK;
}
Status DestoryStack(Stack &S){
  ptrNode p=S.top,tmp;
  while(p){
    tmp=p;
  	p=p->next;
  	free(tmp);
  }
   S.top=NULL;
   S.len=0;
   return OK;
}
Status ClearStack(Stack &S){
  ptrNode p=S.top->next,tmp;
  while(p){
    tmp=p;
  	p=p->next;
  	free(tmp);
  }
   S.top->next=NULL;
   S.len=0;
   return OK;
}
Status StackEmpty(Stack S){
	return S.top->next==NULL;
}
int StackLength(Stack S){
	return S.len;
}
Status GetTop(Stack S,ElemType &e){
	if(StackEmpty(S))return ERROR;
	e=S.top->next->data;
	return OK;
}
Status Push(Stack &S,ElemType e){
   ptrNode newnode=(ptrNode)malloc(sizeof(SNode));
   if(!newnode)return ERROR;
   newnode->data=e;
   newnode->next=S.top->next;
   S.top->next=newnode;
   //
   ++S.len;
   return OK;
}
Status Pop(Stack &S,ElemType &e){
	if(StackEmpty(S))return ERROR;
	//e=S.top->next->data ;
	ptrNode tmp=S.top->next;
	S.top->next=tmp->next;
	free(tmp);
    //
    --S.len;
	return OK;
}
Status StackTraverse(Stack S,Status (*visit)(ElemType)){
	ptrNode p=S.top->next;
	while(p){
		(*visit)(p->data);
		p=p->next;
	}
}