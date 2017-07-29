#include<stdio.h>

void swap(int *x,int *y){
int tmp;
tmp=*x;
*x=*y;
*y=tmp;
}


void rank(){
int x,y,z;
scanf("%d%d%d",&x,&y,&z);
if(x<y)
swap(&x,&y);
if(x<z)
swap(&x,&z);
if(y<z)
swap(&y,&z);
printf("%d %d %d",x,y,z);
}


int main(){

rank();

return 0;}
