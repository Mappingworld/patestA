#include<cstdio>

int s[40000000] = {0};
int main(){
  int i , j= 0;
  int x = 0,y = 0;
  int a = 0;
  scanf("%d %d",&x,&y);
  for(i = 0;i < y;i++){
   for(j = 0;j < x;j++){
     scanf("%d",&a);
     s[a]++;
   }
  }
  int max = s[0];
  int re = 0;
  for(i = 0;i < 40000;i++){
    if(max < s[i]){
      re = i;
      max = s[i];
    }
  }
  printf("%d",re);
}
