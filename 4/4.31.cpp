#include<stdio.h>
#include<string.h>
#include<malloc.h>
void fun(const char *a,const char *b,char **s){
	int lena=strlen(a);
	int lenb=strlen(b);

	int **jz=(int**)malloc(sizeof(int*)*lena);
	for(int m=0;m<lena;m++)
	jz[m]=(int*)malloc(sizeof(int)*lenb);
    int i,j;
    int ai,bj;
    int max=-1;
	for(i=0;i<lena;i++)
		for(j=0;j<lenb;j++)
		{ //printf("hahahah\n");
			if(i==0||j==0){
				if(a[i]==b[j])
					jz[i][j]=1;
				else
					jz[i][j]=0;
			}else{
				if(a[i]==b[j])
					jz[i][j]=jz[i-1][j-1]+1;
				else
					jz[i][j]=0;
			}

			if(jz[i][j]>max){
				max=jz[i][j];
				ai=i;
				bj=j;
			}



		}
printf("%d %d\n",ai,max );
		*s=(char*)malloc(sizeof(char)*(max+1));
		(*s)[max]=0;
		for(;max>0;max--,ai--)
			(*s)[max-1]=a[ai];

		

	//printf("adsffabcdefghiffadsffdsdashhs\n");
}

int main()
{
	/* code */
	char *a="afdskjhfhabcdefghisdjfhhfaffkkklkafjdfjfajdsjjkabcdefghijklmnfjjagsjhhgfajghgfhgfgggggggggggggggggggggag";
	char *b="adsffabcdefghiffadsffdsdashhsghhfgjjjjjjjjabcdefghijklmnjjjjjjjjjjjjjjjjjjjjjjjjfhggkkjhhllljjl";
	char *c;
	fun(a,b,&c);
	printf("%s\n", c);
	return 0;
}