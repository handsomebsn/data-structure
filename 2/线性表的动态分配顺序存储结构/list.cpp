#include "list.h"
Status InitList_Sq(SqList &L){
	L.elem=(ElemType*)malloc(LIST_INT_SIZE*sizeof(ElemType));
	if(!L.elem)return OVERFLOW;
	L.length=0;
	L.listsize=LIST_INT_SIZE;
}
Status ListInsert_Sq(SqList &L,int i,ElemType e){
	if(i<1||i>L.length+1)return ERROR;
	if(L.length>=L.listsize){
		ElemType *newbase=(ElemType*)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
		L.elem=newbase;
		L.listsize+=LISTINCREMENT;
	}
	int ii=i-1;
	int pos=L.length;
	for(;pos>ii;--pos)
		L.elem[pos]=L.elem[pos-1];
	L.elem[pos]=e;
	++L.length;
	return OK;
}
Status ListDelete_Sq(SqList &L,int i,ElemType &e){
	if(i<1||i>L.length||L.length==0)return ERROR;
	int pos=i-1;
	e=L.elem[pos];
	for(;i<L.length;++pos,++i)
		L.elem[pos]=L.elem[pos+1];
	--L.length;
	return OK;

}
int LocateElem_Sq(SqList L,ElemType e,Status (*compare)(ElemType,ElemType)){
	int i=0;
	for(;i<L.length&&(*compare)(e,L.elem[i])!=0;++i);
	if(i==L.length)
		return 0;
	else
		return i+1;
}
void MergeList_Sq(SqList La,SqList Lb,SqList &Lc){



	
}