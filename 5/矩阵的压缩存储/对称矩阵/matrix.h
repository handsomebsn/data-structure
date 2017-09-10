/*对称矩阵存储下三元表示法*/
#include "all.h"
typedef int ElemType;
typedef struct{
	ElemType *base;
	int n;
}Matrix;
Status InitMatrix(Matrix &mat,int _n);
Status Off(Matrix mat,int i,int j,int &off);
Status Assign(Matrix &mat,ElemType e,int i,int j);
Status Value(Matrix &mat,ElemType &e,int i,int j);
Status InitMatrix(Matrix &mat,int _n){
	n=_n;
	mat.base=(ElemType*)malloc(sizeof(ElemType)*n*(n+1)/2);
	if(!mat.base)return ERROR;
	return OK;	
}
Status Off(Matrix mat,int i,int j,int &off){
	if(i>=mat.n||j>=mat.n||i<1||j<1)return ERROR;
	if(i>=j)
		off=(i-1)*i/2+j-1
	else
		off=(j-1)*j+i-1;
	return OK;
}
Status Assign(Matrix &mat,ElemType e,int i,int j){
	int off;
	if(!Off(mat,i,j,off))return ERROR;
	mat.base[off]=e;
	return OK;
}
Status Value(Matrix &mat,ElemType &e,int i,int j){
	int off;
	if(!Off(mat,i,j,off))return ERROR;
	e=mat.base[off];
	return OK;
}
