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


typedef struct
{
	PolyTerm *data;
	int length;
}SqPoly;
SqPoly create(int size){
	SqPoly sq;
	sq.data=(PolyTerm*)malloc(sizeof(PolyTerm)*size);
	sq.length=0;
	return sq;
}

Status insert(SqPoly &sq,int coef,int exp){
PolyTerm pol;
pol.coef=coef;
pol.exp=exp;
 int i;
 for(i=sq.length;i>0&&sq.data[i-1].exp>exp;i--){
 	sq.data[i]=sq.data[i-1];
 }
if(i>0&&sq.data[i-1].exp==exp)return INFEASIBLE;
 sq.data[i]=pol;
 sq.length++;
 return OK;
}


int fun2_39(const SqPoly &sq,int x){
 int s=0,xi=1;
for(int k=0;k<sq.data[0].exp;k++){
    	xi=xi*x;
    }
s=s+sq.data[0].coef*xi;
 for(int i=1;i<sq.length;i++){
    for(int j=0;j<sq.data[i].exp-sq.data[i-1].exp;j++){
    	xi=xi*x;
    }
    s=s+sq.data[i].coef*xi;
 }
return s;
}
void print(const SqPoly &sq){
	int i=0;
	for(i=0;i<sq.length-1;i++){
		printf("%d*x^%d + ",sq.data[i].coef,sq.data[i].exp);
	}
	printf("%d*x^%d\n",sq.data[i].coef,sq.data[i].exp);
}
int main(){
 int n;
 printf("enter n\n");
scanf("%d",&n);
SqPoly sq=create(n);
int coef,exp;
printf("enter n pieces of coef exp\n");
for(int i=0;i<n;i++){
	scanf("%d %d",&coef,&exp);
	insert(sq,coef,exp);
}
print(sq);
int x;
printf("enter x\n");
scanf("%d",&x);
printf("%d\n", fun2_39(sq,x));

	return 0;
}