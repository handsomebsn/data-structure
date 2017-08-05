#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define LIST_INT_SIZE 100
#define LISTINCREMENT 10
#define INFEASIBLE -1//参数不合法
#define OVERFLOW -2
#define OK 1
#define ERROR 0
//typedef int ElemType;
typedef int Status;//函数状态

typedef struct
{
 int coef;
 int exp;	
}PolyTerm;


typedef struct PolyNode
{
	PolyTerm data;
	struct PolyNode *next;
}PolyNode ,*PolyLink;
typedef PolyLink LinkedPloy;
LinkedPloy create(){
	PolyNode *head=(PolyLink)malloc(sizeof(PolyNode));
	head->next=head;
	return head;
}

void insert(LinkedPloy list,int coef,int exp){
	PolyLink pre=list,p=pre->next;
	PolyLink newptr=(PolyLink)malloc(sizeof(PolyNode));
	newptr->data.coef=coef;
	newptr->data.exp=exp;
	while(p!=list&&exp >p->data.exp){
       pre=p;p=p->next;
	}
	if(p!=list&&exp==p->data.exp)return;
	newptr->next=p;
	pre->next=newptr;

}


void print(LinkedPloy list){
	PolyLink p=list->next;
	while(p->next!=list){
		printf("%d*x^%d + ",p->data.coef,p->data.exp);
		p=p->next;
	}
	printf("%d*x^%d\n",p->data.coef,p->data.exp);
}
void fun2_42(LinkedPloy lista,LinkedPloy &listb,LinkedPloy listc){
	PolyLink pre=lista,p=lista->next;
	int k=1;
	PolyLink rear=listc;
	while(p!=lista){
		if(k%2==0){
			pre->next=p->next;
			//
			p->next=rear->next;
			rear->next=p;
			rear=p;
			//
			p=pre->next;
		}else{
			pre=p;p=p->next;
		}
		k++;
	}
	free(listb);
	listb=lista;

}

int main(){
 int n;
 printf("enter n\n");
scanf("%d",&n);
LinkedPloy lista=create();
LinkedPloy listb=create();
LinkedPloy listc=create();
int coef,exp;
printf("enter n pieces of coef exp\n");
for(int i=0;i<n;i++){
	scanf("%d %d",&coef,&exp);
	insert(lista,coef,exp);
}
print(lista);
fun2_42(lista,listb,listc);
print(listb);
print(listc);
	return 0;
}