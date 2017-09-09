#include "array.h"
Status InitArray(Array &A,int dim,...){
	va_list ap;
	if(dim<1||dim>MAX_ARRAY_DIM)
		return ERROR;
	A.dim=dim;
	A.bounds=(int*)malloc(sizeof(int)*dim);
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
	///
	A.base=(ElemType*)malloc(sizeof(ElemType)*elemtotal);
	if(!A.base)return ERROR;
	A.constants=(int*)malloc(sizeof(int)*dim);
	if(!A.constants)return ERROR;
	A.constants[dim-1]=1;//L 
	for(int i=dim-2;i>=0;--i)
		A.constants[i]=A.constants[i+1]*A.bounds[i+1];
	return OK;
}
Status DestoryArray(Array &A){
	A.dim=0;
	free(A.base);
	free(A.bounds);
	free(A.constants);
}
Status locate(Array A,va_list ap,int &off){
	off=0;
	int j;
	//va_start(ap,A.dim);
	for(int i=0;i<A.dim;++i){
		j=va_arg(ap,int);
		if(j<0||j>=A.bounds[i])return ERROR;
		off+=A.constants[i]*j;
	}
	//va_end(ap);
	return OK;
}
Status Value(Array A,ElemType &e,...){
	int off;
	va_list ap;
	va_start(ap,e);
	if(locate(A,ap,off)==ERROR)return ERROR;
	va_end(ap);
	e=A.base[off];

}
Status Assign(Array &A,ElemType e,...){
	int off;
	va_list ap;
	va_start(ap,e);
	if(locate(A,ap,off)==ERROR)return ERROR;
	//printf("%d\n",off );
	va_end(ap);
	A.base[off]=e;
}