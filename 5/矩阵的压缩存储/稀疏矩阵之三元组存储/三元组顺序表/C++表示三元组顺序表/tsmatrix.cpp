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
		base=new T[tu];
		last=0;
	}
	~TSmatrix(){
		delete[] base;
		base=NULL;
	}
	Status assign(T e,int i,int j);
	int m,n;
	int tu;
	T *base;
	int last;
};
template<typename T> 
Status TSmatrix<T>::assign(T e,int i,int j){

}


#endif



int main(int argc, char const *argv[])
{
	/* code */
	try {
		TSmatrix<int> t(5,6,10);
	}catch(const char *e){
		std::cout<<"hahah";
	}
	return 0;
}