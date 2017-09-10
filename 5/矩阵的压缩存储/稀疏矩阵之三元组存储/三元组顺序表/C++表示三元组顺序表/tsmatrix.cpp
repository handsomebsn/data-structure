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
	TSmatrix(int _m,int _n,int _tu){
		if(_tu>_m*_n)throw "111";
		m=_m;
		n=_n;
		tu=_tu;
		base=new Triple<T>[tu];
		last=0;
	}
	~TSmatrix(){
		delete[] base;
		base=NULL;
	}
	void print(){
		for(int p=0;p<last;++p)
			std::cout<<base[p].e<<" "<<base[p].i<<" "<<base[p].j<<std::endl;
	}
	Status assign(T e,int row,int col);
	int m,n;
	int tu;
	Triple<T> *base;
	int last;
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
	return 0;
}