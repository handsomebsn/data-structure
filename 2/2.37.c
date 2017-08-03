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
void print(LinkList list);
LinkList create(){
  LinkList head=(LinkList)malloc(sizeof(LNode));
  head->next=head;
  head->prior=head;
  return head;
}

Status insert(LinkList list,int i,ElemType x){
	LinkList pre=list,p=pre->next;
	int k=1;
	while(p!=list&k<i){
     pre=p;p=p->next;k++;
	}
	if(k!=i)return INFEASIBLE;
	LinkList newptr=(LinkList)malloc(sizeof(LNode));
	newptr->data=x;
	newptr->next=pre->next;
	newptr->prior=pre;

    pre->next=newptr;
    p->prior=newptr;

}
Status fun2_37(LinkList list){
	if(!list||!list->next)return ERROR;
	LinkList pre=list,p=pre->next;int k=1;
	LinkList tmphead=(LinkList)malloc(sizeof(LNode));
	tmphead->next=tmphead->prior=tmphead;
	while(p!=list){
		//pre=p; p=p->next;
		if(k%2!=0){
         pre=p;p=p->next;
		}else{
			pre->next=p->next;
			p->next->prior=pre;
            //
            p->next=tmphead->next;
            p->prior=tmphead;
            tmphead->next->prior=p;
            tmphead->next=p;
			//
			p=pre->next;
		}

		k++;
	}
	if(tmphead->next==tmphead)return ERROR;
	list->prior->next=tmphead->next;
	tmphead->next->prior=list->prior;
	list->prior=tmphead->prior;
	tmphead->prior->next=list;
	//print(tmphead);
free(tmphead);
}

void print(LinkList list){
	if(!list)return;
	LinkList p=list->next;
	while(p!=list){
		printf("%d ", p->data);
		p=p->next;
	}
	printf("\n");

}


int main(){
  LinkList list =create();
  for(int i=1;i<=20;i++){
  	insert(list,i,i);
  }
print(list);
fun2_37(list);
print(list);

	return 0;
}