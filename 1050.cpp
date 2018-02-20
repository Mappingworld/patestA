//第一次只得了3分查不出错误
#include<cstdio>
#include<cstring>
const int N = 10001;
int main(){
  int i ,j = 0;
  char s[N];
  char ss[N];
  gets(s);
  gets(ss);
  int s1 = strlen(s);
  int ss1 = strlen(ss);
  for(i = 0;i < s1;i++){
     if(strchr(ss,s[i])== NULL)
      printf("%c",s[i]);
  }

}



