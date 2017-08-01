#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define LIST_INT_SIZE 100
#define LISTINCREMENT 10
#define INFEASIBLE -1//参数不合法
#define OK 1
typedef int ElemType;
typedef int Status;//函数状态
typedef struct{
  ElemType *elem;//动态数组
  int length;//当前长度
  int listsize;//当前分配的存储容量

}Sqlist;//顺序表类型
//创建顺序表
Sqlist createsqlist(int listsize){
  Sqlist va;
  va.elem=(ElemType*)malloc(sizeof(ElemType)*listsize);
  va.listsize=listsize;
  va.length=0;
  return va;
}

//插入x使得顺序表从小到大
void InsertUp(Sqlist &va,ElemType x){
   int i;
  for(i=va.length;i>0&&x<va.elem[i-1];i--)
  va.elem[i]=va.elem[i-1];
  va.elem[i]=x;
  va.length++;
}
//在末尾添加元素
void InsertEnd(Sqlist &va,ElemType x){
	va.elem[va.length]=x;
        va.length++;
}

void print(const Sqlist &a){
 for(int i=0;i<a.length-1;i++)
 printf("%d ",a.elem[i]);
 printf("%d",a.elem[a.length-1]);
 printf("\n");
}
// 将A、B求交后的结果放在C表中,1利用A的空间、2不存在相同的元素
Status ListCross_Sq1(Sqlist &A,const Sqlist &B,Sqlist &C){
	int i=0,j=0;int m=0;
  int alength=A.length;
  A.length=0;
 while(i<alength&&j<B.length){
 	if(A.elem[i]==B.elem[j])
 		{ if(A.length==0||(A.length>0&&A.elem[A.length-1]!=A.elem[i])){ A.elem[A.length]=A.elem[i];A.length++;} i++;j++;}
 	else if(A.elem[i]>B.elem[j])
 		j++;
 	else
 		i++;
 }
free(C.elem);
C=A;

}

// 将A、B求交后的结果放在C表中,1利用A的空间、2不存在相同的元素
Status ListCross_Sq(Sqlist &A,const Sqlist &B,Sqlist &C){
	int i=0,j=0;//int k=0;
  int alength=A.length;
  A.length=0;
 while(i<alength&&j<B.length){
 	if(A.elem[i]==B.elem[j])
 		{ 
 			if(A.length==0||A.elem[A.length-1]!=A.elem[i])
 			 { A.elem[A.length]=A.elem[i];A.length++;} 
				i++;j++;
        }
 	else if(A.elem[i]>B.elem[j])
 		j++;
 	else
 		i++;
 }
free(C.elem);
C=A;

}


int main(){
	srand(time(NULL));
Sqlist a=createsqlist(100);
Sqlist b=createsqlist(100);
Sqlist c=createsqlist(100);
for(int i=0;i<20;i++){
	InsertUp(a,rand()%20);
}
print(a);
for(int i=0;i<20;i++){
	InsertUp(b,rand()%20);
}
print(b);
ListCross_Sq(a,b,c);
printf("after ListCross_Sq(a,b,c)\n");

 print(a);
    return 0;
}
