#include<stdio.h>
#include<stdlib.h>
#include<math.h>
float sqrt(float A,float p,float e){
	if(fabs(p*p-A)<e)return p;
	else return sqrt(A,(p+A/p)/2,e);
}

float sqrt1(float A,float p,float e){
	while(fabs(p*p-A)>=e){
		p=(p+A/p)/2;
	}
	return p;
}

int main(int argc, char const *argv[])
{
	/* code */
	printf("%f\n",sqrt1(9,666,0.0000001) );
	return 0;
}