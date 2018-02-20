#include<cstdio>
#include<cstring>
int main(){
  char g[1010];
  char ne[1010];
  scanf("%s",g);
  scanf("%s",ne);
  int gw = strlen(g);
  int nw = strlen(ne);
  int i,j = 0;int que = 0;
  for(i = 0;i < nw;i++){
    for(j = 0;j < gw;j++){
      if(ne[i] == g[j]){
        g[j] = '_';
        break;
      }
    }
    if(j == gw)
      que ++;
  }
  if(que == 0)
    printf("Yes %d",gw-nw);
  else
    printf("No %d",que);
}
