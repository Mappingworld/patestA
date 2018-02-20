#include<cstdio>
#include<cstring>

int main(){
  char f[100];
  char s[100];
  char re[100];
  scanf("%s",f);
  scanf("%s",s);
  int f1 = strlen(f);
  int s1 = strlen(s);
  int i = 0,l = 0,j = 0, k = 0;
  for(l = 0;l < s1;l++){
    if(s[l] != f[i]&&i < f1){
      if(97 <= f[i] && f[i] <= 122)
         f[i] = f[i] -32;
      for(j = 0;j <= k;j++){
        if(f[i] == re[j])
          break;
      }
      if(j > k)
        re[k++] = f[i];
    l--;
    }
    i++;
  }
  for(;i < f1;i++){
    if(97 <= f[i] && f[i] <= 122)
         f[i] = f[i] -32;
      for(j = 0;j <= k;j++){
        if(f[i] == re[j])
          break;
      }
      if(j > k)
        re[k++] = f[i];

  }
  for(i = 0;i < k;i++){
    printf("%c",re[i]);
  }
}
