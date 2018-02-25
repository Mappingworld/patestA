#include<cstdio>

const int N = 100000;//100000
int main(){
  int num = 0;
  int amou = 0;
  int i = 0;
  int s[N] ={0};
  int a = 0;
  int re[100000] = {0};
  scanf("%d %d",&num,&amou);
  for(i = 0;i < num;i++){
    scanf("%d",&a);
    if(a > amou)
      s[i] = -1;
    else
      s[i] = a;
  }
  int flg = 10000;
  int j = 0;
  int k = 0;
  int res = 0;
  for(i = 0;i < num;i++){
    if(s[i] != -1){
      res = 0;
     for(j = i;j < num;j++){
       if(s[j] == -1)
         break;
       res += s[j];
       if(res == amou){
         if(flg != 0){
           flg = 0;
           k = 0;
         }
          re[k++]=i;
          re[k++]=j;
       }
       if(res > amou && res < flg){
           flg = res;
           k = 0;
           re[k++] = i;
           re[k++] = j;
           break;
       }
       if(res > amou && res == flg){
           re[k++] = i;
           re[k++] = j;
           break;
       }
       if(res > amou && res > flg){
           break;
       }

     }
    }
  }
  for(i = 0;i < k;i++){
    printf("%d-%d\n",re[i]+1,re[i+1]+1);
    i = i+1;
  }

}
