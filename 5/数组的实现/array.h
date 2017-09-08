#ifndef __LARRAY__
#define __LARRAY__
#include "all.h"
#include<stdarg.h>
#define MAX_ARRAY_DIM 8
typedef struct
{
	ElemType *base;
	int dim;
	int *bounds;
	int *constants;
}Array;
Status InitArray(Array &A,int dim,...);
Status DestoryArray(Array &A);
Status Value(Array A.ElemType &e,...);
Status Assign(Array &A,ElemType e,...);
#endif
Status InitArray(Array &A,int dim,...){
	if(dim<1||dim>MAX_ARRAY_DIM)
		return ERROR;
	A.dim=dim;
	A.bounds=(int)malloc(siezof(int)*dim);
	if(!A.bounds)
		return OVERFLOW;
	int elemtotal=1;
	va_start(ap,dim);
	for(int i=0;i<dim;i++){
		A.bounds[i]=va_arg(ap,int);
		if(A.bounds[i]<0)return ERROR;
		elemtotal*=A.bounds[i];
	}
	va_end(ap);
}
Status DestoryArray(Array &A);
Status Value(Array A.ElemType &e,...);
Status Assign(Array &A,ElemType e,...);