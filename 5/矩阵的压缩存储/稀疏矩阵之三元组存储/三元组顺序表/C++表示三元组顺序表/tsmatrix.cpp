#ifndef __LCCTSMATRIX
#define __LCCTSMATRIX
#include <iostream>
typedef int Status;
template<typename ElemType>
struct Triple{
	int i,j;
	ElemType e;
};
template<typename T>
class TSmatrix
{
public:
	TSmatrix(){
		m=0;
		n=0;
		tu=0;
		base=NULL;
		last=0;
	}
	TSmatrix(const TSmatrix &mat){

		m=mat.m;
		n=mat.n;
		tu=mat.tu;
		last=mat.last;
		base=new Triple<T>[tu];
		for(int p=0;p<tu;++p)
			base[p]=mat.base[p];
	}

	TSmatrix(int _m,int _n,int _tu){
		if(_tu>_m*_n)throw "111";
		m=_m;
		n=_n;
		tu=_tu;
		base=new Triple<T>[tu];
		last=0;
	}
	~TSmatrix(){
		if(base)
		delete[] base;
		base=NULL;
	}
	void print(){
		for(int p=0;p<last;++p)
			std::cout<<base[p].e<<" "<<base[p].i<<" "<<base[p].j<<std::endl;
	}
	Status assign(T e,int row,int col);
	Status sumassign(T e,int row,int col);
private:
	int m,n;
	int tu;
	Triple<T> *base;
	int last;
public:
	TSmatrix<T>& operator=(const TSmatrix<T> &mat);
	TSmatrix<T> operator+(const TSmatrix<T> &mat);
private:
	Status locate(int row,int col,int &p);
};
template<typename T> 
Status TSmatrix<T>::assign(T e,int row,int col){
	int p;
	if(locate(row,col,p)){
		base[p].e=e;
	}else{
		for(p=last;p>0&&base[p-1].i>row;--p)
			base[p]=base[p-1];
		base[p].e=e;
		base[p].i=row;
		base[p].j=col;
		++last;
	}
	return 1;
}
template<typename T>
Status TSmatrix<T>::sumassign(T e,int row,int col){
	int p;
	if(locate(row,col,p)){
		base[p].e+=e;
	}else{
		for(p=last;p>0&&base[p-1].i>row;--p)
			base[p]=base[p-1];
		base[p].e=e;
		base[p].i=row;
		base[p].j=col;
		++last;
	}
	return 1;
}

template<typename T>
Status TSmatrix<T>::locate(int row,int col,int &p){
	int i=0;
	int j=last-1;
	while(i<=j){
		p=(i+j)/2;
		if(row<base[p].i)
			j=p-1;
		else if(row>base[p].i)
			i=p+1;
		else if(row==base[p].i&&col==base[p].j)
			break;
	}
	if(i<=j)
		return 1;
	else
		return 0;
}

template<typename T>
TSmatrix<T>& TSmatrix<T>::operator=(const TSmatrix<T> &mat){
	m=mat.m;
	n=mat.n;
	tu=mat.tu;
	last=mat.last;
	base=new Triple<T>[tu];
	for(int p=0;p<tu;++p)
		base[p]=mat.base[p];
	return *this;
}
template<typename T>
TSmatrix<T> TSmatrix<T>::operator+(const TSmatrix<T> &mat){
	if(m!=mat.m||n!=mat.n)throw "ERROR IS M1!=M2 N1!=N2";
	TSmatrix<T> tmp(m,n,tu+mat.tu);
	for(int p=0;p<tu;++p)
		tmp.sumassign(base[p].e,base[p].i,base[p].j);
	for(int p=0;p<mat.tu;++p)
		tmp.sumassign(mat.base[p].e,mat.base[p].i,mat.base[p].j);
	tmp.tu=tmp.last;
	return tmp;
}

#endif



int main(int argc, char const *argv[])
{
	/* code */
	TSmatrix<int> t(5,6,10);
	t.assign(8,1,8);
	t.assign(10,3,10);
	t.assign(9,2,9);
	//
	t.assign(18,3,10);
	t.print();
	std::cout<<std::endl;
	TSmatrix<int> t1;
	t1=t;
	t1.print();
	std::cout<<std::endl;
	TSmatrix<int> tsum;
	tsum=t+t1;
	tsum.print();
	return 0;
}