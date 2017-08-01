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
//
void print(const Sqlist &a){
 for(int i=0;i<a.length-1;i++)
 printf("%d ",a.elem[i]);
 printf("%d",a.elem[a.length-1]);
 printf("\n");
}

//逆置线性表
Status ListOppose(Sqlist &va){
  int m=va.length-1;
  int n=m/2;
  ElemType tmp;
  for(int i=0;i<n;i++){
    //va.elem[i]<->va.elem[m-i]
    tmp=va.elem[i];
    va.elem[i]=va.elem[m-i];
    va.elem[m-i]=tmp;
  }
}

int main(){
  srand(time(NULL));
  Sqlist va=createsqlist(888);
  for(int i=0;i<5;i++)
  {
    InsertUp(va,rand()%10);
  }
print(va);
ListOppose(va);
printf("after ListOppose(va)\n" );
print(va);
  return 0;
}
