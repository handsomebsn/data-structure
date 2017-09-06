#include "list.h"
#include <time.h>
#include <stdlib.h>
Status visit(ElemType e){
	printf("%d ", e);
}


int main(int argc, char const *argv[])
{
	/* code */
	LinkList L;
	InitList(L);
	Link newnode;
    for(int i=0;i<10;i++){
		MakeNode(newnode,rand()%100);
        Append(L,newnode);
        //InsFirst(L.head,newnode);
    }
    ListTraverse(L,visit);
	return 0;
}