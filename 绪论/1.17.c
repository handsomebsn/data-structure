#include<stdio.h>
/*求k阶斐波拉契第m项的系数*/
int fb(int k,int m){
   if (m<k) return 0;
   else if(m==k||m==k+1) return 1;
    else return 2*fb(k,m-1)-fb(k,m-1-k);
}

int main(){
for(int m=1;m<=18;m++)
printf("%d ",fb(3,m));//m大于等于4时候每一项等于前三项的和---3阶斐波拉契序列//m大于等于5时每一项等于前一项的2倍减去第m-1-3项
return 0;}
