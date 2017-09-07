#include "list.h"
Status MakeNode(Link &p,ElemType e){
	p=(Link)malloc(sizeof(LNode));
	
	if(!p)
		return ERROR;
	p->data=e;
	p->next=NULL;
	return ERROR;
}
void FreeNode(Link &p){
	if(p){
      Link tmp=p;
      p=p->next;
      free(tmp);
	}
}
Status InitList(LinkList &L){
	L.head=L.tail=(Link)malloc(sizeof(LNode));
	if(!L.head)return ERROR;
	L.head->next=NULL;
	L.len=0;
}
Status DestoryList(LinkList &L){
	Link p=L.head;
	while(p)
		FreeNode(p);
	L.head=L.tail=NULL;
	L.len=0;
}
Status ClearList(LinkList &L){
	Link p=L.head->next;
	while(p)
		FreeNode(p);
	L.tail=L.head;
	L.head->next=NULL;
	L.len=0;
}
Status InsFirst(Link h,Link s){
	s->next=h->next;
	h->next=s;
	return OK;
}
Status DelFirst(Link h,Link &q){
	q=h->next;
	h->next=q->next;
	return OK;
}
Status Appand(LinkList &L,Link s){
	L.tail->next=s;
    Link p=s;
    int i=1;
    while(p->next){p=p->next;++i;}
    L.tail=p;
    L.len+=i;
    return OK;
}
Status Appand(LinkList &L,ElemType e){
	Link newnode=(Link)malloc(sizeof(LNode));
	if(!newnode)return OVERFLOW;
	newnode->data=e;
	newnode->next=NULL;
	L.tail->next=newnode;
	L.tail=newnode;
	return OK;
}
Status Remove(LinkList &L,Link &q){
	if(L.len==0)return ERROR;
	q=L.tail;
	L.tail=PriorPos(L,q);
	L.tail->next=NULL;
	--L.len;
	return OK;	
}
Status InsBefore(LinkList &L,Link &p,Link s){

	if(!InsFirst(PriorPos(L,p),s))return ERROR;
	//if(p==L.tail)L.tail=s;
	++L.len;
	p=s;
	return OK;
}
Status InsAfter(LinkList &L,Link &p,Link s){
	if(!InsFirst(p,s))return ERROR;
	if(p==L.tail)L.tail=s;
	++L.len;
	p=s;
	return OK;
}
Status SetCurElem(Link &p,ElemType e){
	p->data=e;
}
ElemType GetCurElem(Link p){
	return p->data;
}
Status ListEmpty(LinkList L){
	return L.len==0;
}
Postion GetHead(LinkList L){
	return L.head;
}
Postion GetLast(LinkList L){

	return L.tail;
}
Postion PriorPos(LinkList L,Link p){
	Link pre,tmp;
	pre=L.head;tmp=pre->next;
	while(tmp&&tmp!=p){
		pre=p;
		p=p->next;
	}
	return pre;
}
Postion NextPos(LinkList L,Link p){
	return p->next;
}
Status LocatePos(LinkList L,int i,Link &p){
	if(i<1||i>L.len)return ERROR;
	int k=1;
	p=L.head->next;
	while(p&&k<i){
		p=p->next;
		++k;
	}
	return OK;
}
Postion LocateElem(LinkList L,ElemType e,int (*compare)(ElemType,ElemType)){
	Link p=L.head->next;
	while(p&&(*compare)(e,p->data)!=0)p=p->next;
	return p;
}
Status ListTraverse(LinkList L,Status (*visit)(ElemType)){
	Link p=L.head->next;
	while(p){
		//printf("list ---\n");
		(*visit)(p->data);
		p=p->next;
	}
	return OK;
}
Status ListInsert(LinkList &L,int i,ElemType e){
	if(i<1||i>L.len+1)return ERROR;
	Link s;
	if(!MakeNode(s,e))return ERROR;
	Link h;
	if(!LocatePos(L,i-1,h))return ERROR;
	if(!InsFirst(h,s))return ERROR;
	return OK;
}
Status MergeList(LinkList &La,LinkList &Lb,LinkList &Lc,int (*compare)(ElemType,ElemType)){

	return OK;
}