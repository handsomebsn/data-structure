int main(){
	srand(time(NULL));
LinkList a=createLinklist();
LinkList b=createLinklist();
LinkList c=createLinklist();
for(int i=0;i<20;i++){
	InsertUp(a,rand()%20);
}
print(a);
for(int i=0;i<20;i++){
	InsertUp(b,rand()%20);
}
print(b);
ListCross(a,b,c);
printf("after ListCross(a,b,c)\n");

 print(c);
    return 0;
}
