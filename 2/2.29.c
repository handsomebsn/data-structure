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




//求A=A-B∩C,利用A原有的空间
/*
 已知A，B和C为三个递增有序的线性表，现要求
 对A表作如下操作：删去那些既在B表中出现，又
 在C表中出现的元素。试对顺序表编写实现上述
 操作的算法，并分析你的算法的时间复杂度
 （注意：同一表中各元素值可能相同）。

*/
Status fun2_29(Sqlist &va,const Sqlist &vb,const Sqlist &vc){
    int a=0,b=0,c=0;
    int count=0;
    while(a<va.length&&b<vb.length&&c<vc.length){
            if(vb.elem[b]>vc.elem[c])
              c++;
            else if(vb.elem[b]<vc.elem[c])
              b++;
            else{
                //while(va.elem[a]<vb.elem[b])
                while(a<va.length&&va.elem[a]<vb.elem[b])
                  {va.elem[count]=va.elem[a];count++;a++;}
               while(a<va.length&&va.elem[a]==vb.elem[b])
                      a++;
              b++;c++;
            }
  }
  while(a<va.length){
    va.elem[count]=va.elem[a];
    count++;
    a++;

  }


  va.length=count;
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
for(int i=0;i<20;i++){
  InsertUp(c,rand()%20);
}
print(c);


fun2_29(a,b,c);
printf("after fun2_29(a,b,c)  a=a-b∩c\n");

 print(a);
    return 0;
}




