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
Status insert(SqPoly &sq, const PolyTerm &pol){
int exp=pol.exp;
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

void sub(const SqPoly &sqa,const SqPoly &sqb,SqPoly &sqc){
 int a=0,b=0;
 free(sqc.data);PolyTerm pol;
 sqc=create(sqa.length+sqb.length);
 	while(a<sqa.length&&b<sqb.length){
 		if(sqa.data[a].exp<sqb.data[b].exp)
 		{	
 			insert(sqc,sqa.data[a]);
 			a++;
 		}
 		else if(sqa.data[a].exp>sqb.data[b].exp)
 		{	pol.coef=0-sqb.data[b].coef;
 			pol.exp=sqb.data[b].exp;
 			insert(sqc,pol);
 			b++;
 		}
 		else{
 			if(sqa.data[a].coef!=sqb.data[b].coef){
 				pol.coef=sqa.data[a].coef-sqb.data[b].coef;
 				pol.exp=sqa.data[a].exp;
 				insert(sqc,pol);
 				a++;b++;
 			}
 		}
 	}
 	while(a<sqa.length){
 		insert(sqc,sqa.data[a]);
 		a++;
 	}
 	while(b<sqb.length){
      		pol.coef=0-sqb.data[b].coef;
 			pol.exp=sqb.data[b].exp;
 			insert(sqc,pol);
 			b++;
 	}
}


int main(){
 int n;
 printf("enter n\n");
scanf("%d",&n);
SqPoly sqa=create(n);
int coef,exp;
printf("enter n pieces of coef exp\n");
for(int i=0;i<n;i++){
	scanf("%d %d",&coef,&exp);
	insert(sqa,coef,exp);
}
print(sqa);


 printf("enter n\n");
scanf("%d",&n);
SqPoly sqb=create(n);

printf("enter n pieces of coef exp\n");
for(int i=0;i<n;i++){
	scanf("%d %d",&coef,&exp);
	insert(sqb,coef,exp);
}
print(sqb);
SqPoly sqc=create(100);
sub(sqa,sqb,sqc);
print(sqc);

	return 0;
}