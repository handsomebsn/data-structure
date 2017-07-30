#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define LIST_INT_SIZE 100
#define LISTINCREMENT 10
#define INFEASIBLE -1//参数不合法
#define OK 1
typedef int ElemType;
typedef int Status;//函数状态
typedef struct LNode{
  ElemType data;
  struct LNode *next;
}LNode,*LinkList;//线性链表类型

//无头结点的单链表
Status insert(LinkList &list,int i,ElemType x){
	LinkList pre=list,newptrnode;
	int k=2;
	if(!list&&i>1) return -999;
	if(i==1){
    	newptrnode=(LinkList)malloc(sizeof(LNode));
    	newptrnode->data=x;
    	newptrnode->next=list;
    	list=newptrnode;
	}else{
		//if(pre) printf("afdfddfsdfs\n");
		while(k<i&&pre->next){ pre=pre->next;k++;}
		//printf("%d %d\n",k,pre->next );
		if(k<i&&!pre->next) return INFEASIBLE;
		newptrnode=(LinkList)malloc(sizeof(LNode));
    	newptrnode->data=x;
		   newptrnode->next=pre->next;
          pre->next=newptrnode;
	}
	return OK;
}
//
Status Delete(LinkList list,int i){



}

void print(LinkList list){

  //list=list->next;
  int i=1;
  while(list){
    printf("%d %d\n",i,list->data);
    list=list->next;
    i++;
  }

}
Status DeleteAndInsertSub(LinkList &la,LinkList &lb,int i,int j,int len)
{   int k=1;
	LinkList ha=(LinkList)malloc(sizeof(LNode));
	LinkList hb=(LinkList)malloc(sizeof(LNode));
	ha->next=la;
	hb->next=lb;
	LinkList pre=ha;LinkList p=ha->next;
	while(k<i&&p){pre=p;p=p->next;k++;}
	if(!p){free(ha);free(hb);return INFEASIBLE;}
	LinkList q=p;k=1;
	while(k<len&&q){q=q->next;k++;}
	if(!q){free(ha);free(hb);return INFEASIBLE;}
	if(pre!=ha)
	pre->next=q->next;
	else
		la=q->next;
     LinkList sre=hb;LinkList s=hb->next;k=1;
     while(k<j&&sre){sre=s;if(s)s=s->next;k++;}
     if(!sre)return INFEASIBLE;
     if(sre!=hb)
     {sre->next=p;q->next=s;}
 		else
 	 {q->next=lb;lb=p;}
     free(ha);free(hb);
}





int main(){
srand(time(NULL));
LinkList la=NULL;
LinkList lb=NULL;
	for(int i=0;i<rand()%20;i++)
	insert(la,1,rand()%100);
	for(int i=0;i<rand()%20;i++)
	insert(lb,1,rand()%100);
print(la);
printf("\n");
print(lb);
int i,j,len;
printf("please  enter i j len \n");
scanf("%d%d%d",&i,&j,&len);
DeleteAndInsertSub(la,lb,i,j,len);
printf("after DeleteAndInsertSub(la,lb,%d,%d,%d)\n",i,j,len);
print(la);
printf("\n");
print(lb);
   	return 0;
}