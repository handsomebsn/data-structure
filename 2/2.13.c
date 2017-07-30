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

typedef struct LNode{
  ElemType data;
  struct LNode *next;
}LNode,*LinkList;//线性链表类型

//创建顺序表
Sqlist createsqlist(int listsize){
  Sqlist va;
  va.elem=(ElemType*)malloc(sizeof(ElemType)*listsize);
  va.listsize=listsize;
  va.length=0;
  return va;
}
//
LinkList createLinklist(){
  LinkList head=(LinkList)malloc(sizeof(LNode));
  head->next=NULL;
  return head;
}

//从顺序表中删除第i个元素起的k个元素
Status DeleteK(Sqlist &a,int i,int k){
	if(i<1||k<0||i+k-1>a.length) return INFEASIBLE;
	for(int j=i-1;j+k<a.length;j++)
	a.elem[j]=a.elem[j+k];
        a.length-=k;
 	return OK;
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
void InsertHead(LinkList list,ElemType x){
  LinkList newptrnode=(LinkList)malloc(sizeof(LNode));
  newptrnode->data=x;
  newptrnode->next=list->next;
  list->next=newptrnode;
}
//
int locate(LinkList list,ElemType x){
  int pos=1;
  list=list->next;
  while(list&&list->data!=x){
    list=list->next;
    pos++;
  }
  if(list)
  return pos;
  else
    return 0;
}

//比较顺序表大小
int cmp(const Sqlist &va,const Sqlist &vb){
	if(va.length==0&&vb.length==0)
	return 0;
        if(vb.length==0)
	return 1;
        if(va.length==0)
	return -1;
     int i,minlength;
    minlength=va.length<vb.length?va.length:vb.length;
    for(i=0;i<minlength;i++){
       if(va.elem[i]!=vb.elem[i])
	return va.elem[i]>vb.elem[i]?1:-1;
     }
    if(va.length==vb.length)
      return 0;
   else
      return va.length>vb.length?1:-1;    
}


void print(const Sqlist &a){
 for(int i=0;i<a.length-1;i++)
 printf("%d ",a.elem[i]);
 printf("%d",a.elem[a.length-1]);
 printf("\n");
}

void print(LinkList list){

  list=list->next;
  int i=1;
  while(list){
    printf("%d %d\n",i,list->data);
    list=list->next;
    i++;
  }

}



int main(){
  ElemType x;
  LinkList list=createLinklist();
  srand(time(NULL));
  for(int i=0;i<100;i++)
  {
    InsertHead(list,rand()%100);
  }
 print(list);
 printf("请输入要找的数\n");
while(true){
  scanf("%d",&x);
  printf("%d属于第%d个数\n",x,locate(list,x));
}
    return 0;
}

