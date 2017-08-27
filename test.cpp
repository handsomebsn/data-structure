int MaxRepSubString(string s,int &l) {
 l = 0;
 int pos = -1,i;
 int max = -1;
 int length = s.length();
 for (i = 0; i < length - 1; i++) {
  string tmp(s, i, length - i);
  int *next = new int[tmp.length()];
  GetNext(tmp, next, tmp.length());
  max = MaxNext(next, tmp.length());
  if (tmp[tmp.length() - 1] == tmp[max]) {
   max = max + 1;
  }
  if (l < max) {
   l = max;
   pos = i;
  }
 }
 return pos;
}