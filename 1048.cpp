#include<cstdio>
const int M =100000;
int main(){
  int num = 0;
  int amou = 0;
  int s[M] = {0};
  int i ,j;
  scanf("%d %d",&num,&amou);
  for(i = 0;i < num;i++){
    scanf("%d",&j);
    s[j]++;
  }
  if((amou % 2 == 0)&&s[amou/2] == 1){
 //  printf("%d \n",amou/2);
    s[amou/2] = 0;
  }

  for(i = 0;i < amou;i++){
    if(s[i] != 0 &&s[amou - i] != 0){
        printf("%d %d",i,amou - i);
        return 0;
    }

  }
  printf("No solution");
}
