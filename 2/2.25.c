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
/*2.25 假设以两个元素依值递增有序排列的线性
表A和B分别表示两个集合（即同一表中的元素值各不相同），现要求
另辟空间构成一个线性表C，其元素为A和B中元素的交集，且表C中的
元素有依值递增有序排列。试对顺序表编写求C的算法。*/
// 将A、B求交后的结果放在C表中
Status ListCross_Sq(const Sqlist &A,const Sqlist &B,Sqlist &C){
	int i=0,j=0;
 while(i<A.length&&j<B.length){
 	if(A.elem[i]==B.elem[j])
 		{InsertEnd(C,A.elem[i]);i++;j++;}
 	else if(A.elem[i]>B.elem[j])
 		j++;
 	else
 		i++;
 }



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

 print(c);
    return 0;
}
