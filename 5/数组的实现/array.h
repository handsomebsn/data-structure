#ifndef __LARRAY__
#define __LARRAY__
#include "all.h"
#include<stdarg.h>
#define MAX_ARRAY_DIM 8
typedef int ElemType;
typedef struct
{
	ElemType *base;
	int dim;
	int *bounds;
	int *constants;
}Array;
Status InitArray(Array &A,int dim,...);
Status DestoryArray(Array &A);
Status locate(Array A,va_list ap,int &off);
Status Value(Array A,ElemType &e,...);
Status Assign(Array &A,ElemType e,...);
#endif
