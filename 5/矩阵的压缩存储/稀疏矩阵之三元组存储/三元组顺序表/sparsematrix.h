#ifndef __SPARSEMATRIX__
#define __SPARSEMATRIX__
#include "all.h"
#define MAXSIZE 12500
typedef struct
{
	int i,int j;
	ElemType e;
}Triple;
typedef struct 
{
	Triple data[MAXSIZE+1];
	int mu,nu,tu;
}TSMatrix;
#endif