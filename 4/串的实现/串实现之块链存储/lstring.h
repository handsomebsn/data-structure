#define CHUNKSIZE 80
typedef char ElemType;
typedef struct Chunk
{
	ElemType ch[CHUNKSIZE];
	struct Chunk *next;

}Chunk;
typedef struct
{
	Chunk *head,*tail;
	int curlen;
}LString;