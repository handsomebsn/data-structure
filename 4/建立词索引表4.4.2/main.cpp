#define MAXBOOKNUM 1000
#define MAXKEYNUM 2500
#define MAXLINELEN 500
#define MAXWORDNUM 10
#include "list.h"
#include "hstring.h"
#include<cstring>
typedef struct{
	char *item[MAXWORDNUM];
	int last;
}WordListType;

typedef struct 
{
	HString key;
	LinkList bnolist;
}IdxTermType;

typedef struct
{
	IdxTermType item[MAXKEYNUM+1];
	int last;
}IdxListType;

char *buf;
WordListType wdlist;
void InitWordList(WordListType &wdlist);
void InsWordList(WordListType &wdlist,const char *str);
HString GetWord(WordListType wdlist,int xiabiao);
void ClearWordList(WordListType &wdlist);
void InitIdxList(IdxListType &idxlist);
void GetLine(FILE *f);
void ExtractKeyWord(ElemType &bno);
int LocateKey(IdxListType idxlist,HString key);
Status InsIdxList(IdxListType &idxlist,ElemType bno);
Status visit(ElemType e);
void PutText(FILE *g,IdxListType idxlist);

void InitWordList(WordListType &wdlist){
	wdlist.last=0;
}
void InsWordList(WordListType &wdlist,const char *str){
	if(wdlist.last==MAXWORDNUM)return;
	//
	int len=0;
	for(;str[len];++len) ;
	wdlist.item[wdlist.last]=(char*)malloc(sizeof(char)*(len+1));
	strcpy(wdlist.item[wdlist.last],str);
	++wdlist.last;
}
HString GetWord(WordListType wdlist,int xiabiao){
	HString tmp;
	StrAssign(tmp,wdlist.item[xiabiao]);
	return tmp;
}
void ClearWordList(WordListType &wdlist){
	for(int i=0;i<wdlist.last;++i)
		free(wdlist.item[i]);
	wdlist.last=0;
}
void InsIdxList(IdxListType &idxlist){
	StrAssign(idxlist.item[0].key," ");
	InitList(idxlist.item[0].bnolist);
	idxlist.last=0;
}
void InitIdxList(IdxListType &idxlist){
	idxlist.last=0;
}

void GetLine(FILE *f){
	size_t len=0;
	getline(&buf,&len,f);
}
void ExtractKeyWord(ElemType &bno){
	char str[MAXLINELEN];
	bno=0;
	int i;
	for(i=0;buf[i]&&buf[i]!=' ';++i)
	bno=bno*10+buf[i]-'0';
	++i;
	///////////////
	int j=0;
	while(buf[i]!='\n'){//gai zhu yi
		for(j=0;buf[i]!='\n'&&buf[i]!=' ';++i,++j)
			str[j]=buf[i];
		str[j]='\0';
		if(buf[i]==' ')
		++i;
	//printf("%s\n",str );
	InsWordList(wdlist,str);
	}
	free(buf);
}
int LocateKey(IdxListType idxlist,HString key){//up up sort er fen cha zhao
	int i=1,j=idxlist.last;
	int f;
	while(i<=j){
		f=(i+j)/2;
		if(StrCompare(key,idxlist.item[f].key)==0)
			break;
		else if(StrCompare(key,idxlist.item[f].key)<0)
		j=f-1;
		else
		i=f+1;
	}
	if(i>j)
		return 0;
	else
		return f;

}
Status InsIdxList(IdxListType &idxlist,ElemType bno){
	HString key;
	int j=0;
	for(int i=0;i<wdlist.last;++i)
	{
		key=GetWord(wdlist,i);
		//ShowString(key);
		//printf("\n");
		j=LocateKey(idxlist,key);
		if(j){
			Appand(idxlist.item[j].bnolist,bno);
			//printf("you\n");
		}else{
			int m=idxlist.last+1;
			for(;m>1&&StrCompare(idxlist.item[m-1].key,key)>0;--m)
				idxlist.item[m]=idxlist.item[m-1];
			//ShowString(key);
			//printf("%d\n",m );
			idxlist.item[m].key=key;
			++idxlist.last;
			//
			InitList(idxlist.item[m].bnolist);
			Appand(idxlist.item[m].bnolist,bno);
		}
	}
	ClearWordList(wdlist);
	return OK;
}
Status visit(ElemType e){
	printf("%d ", e);
}
void PutText(FILE *g,IdxListType idxlist){
	//ShowString(idxlist.item[1].key);

	for(int i=1;i<idxlist.last;++i)
	{
		ShowString(idxlist.item[i].key);
		printf(" ");
		ListTraverse(idxlist.item[i].bnolist,visit);
		printf("\n");
	}

}
int main()
{
	/* code */
	IdxListType idxlist;
	InitIdxList(idxlist);
	FILE *f=fopen("f.txt","r");
	ElemType bno;

	while(!feof(f)){
		GetLine(f);
		//printf("%s", buf);
		ExtractKeyWord(bno);
		InsIdxList(idxlist,bno);
	}
   PutText(f,idxlist);
	return 0;
}