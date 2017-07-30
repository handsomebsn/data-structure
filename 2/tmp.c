int main(){
  srand(time(NULL));
  LinkList list=createLinklist();
  for(int i=0;i<5;i++)
  {
    InsertUp(list,rand()%10);
  }
print(list);
ListOppose(list);
printf("after ListOppose(list)\n" );
print(list);
  return 0;
}