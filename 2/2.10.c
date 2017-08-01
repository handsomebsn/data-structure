#include<stdio.h>
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

//从顺序表中删除第i个元素起的k个元素
Status DeleteK(Sqlist &a,int i,int k){
	if(i<1||i>a.length||k<0||i+k-1>a.length) return INFEASIBLE;
	for(int j=i-1;j+k<a.length;j++)
	a.elem[j]=a.elem[j+k];
        a.length-=k;
 	return OK;
}
int main(){




return 0;}
