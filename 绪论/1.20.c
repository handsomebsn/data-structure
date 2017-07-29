#include<stdio.h>
void f(){
int x,n;
printf("请输入x和n\n");
scanf("%d%d",&x,&n);
printf("请输入a0,a1,a2....");
int tmp=1;//x的i次方
int sum=0;//结果
int a;
  for(int i=0;i<n;i++){
   scanf("%d",&a);  
       sum+=a*tmp;
       tmp*=x;
   }
   
printf("%d",sum);
}
int main(){

f();

return 0;}
