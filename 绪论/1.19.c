#include<stdio.h>
#include<stdlib.h>
#define MAXINT 99999
#define OK 0
int fun(int a[],int arrsize){
 a[0]=1;
for(int i=1;i<arrsize;i++){
if(a[i-1]*i*2>MAXINT)
return i;
a[i]=(a[i-1]*i)<<1;

}  
printf("OK\n");
return OK;
}
int main(){
printf("请输入a[arrsize]的arrsize的值\n");
int arrsize;
scanf("%d",&arrsize);
int *a=(int*)malloc(sizeof(int));
fun(a,arrsize);

return 0;
}
