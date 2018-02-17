//std::sort()参数含义
#include<cstdio>
#include<cstring>
#include<algorithm>
const int N = 30000;

struct n{
 char id[15];
 int score;
 int qunid;
 int qunci;
 int zci;
}p[N];
bool ss(n a,n b){
   if(a.score!=b.score){
      return a.score > b.score;
   }
   return a.qunci < b.qunci;
}

bool sss(n a,n b){
   if(a.score != b.score){
     return a.score > b.score;
   }
   if(strcmp(a.id,b.id) < 0){
     return 1;
   }
   else
    return 0;

}
int main(){
int time = 0;
scanf("%d",&time);
int num[110] = {0};
int i ,j ,t,k= 0;
for(i = 0;i < time;i++){
  scanf("%d",&num[i]);
  for(j = 0;j < num[i];j++){
    scanf("%s %d",p[k].id,&p[k].score);
    p[k].qunid = i + 1;
    p[k].qunci = j;
    k++;
  }

  std::sort(p+k-num[i],p+k,ss);
   p[k-num[i]].qunci = 1;
  for(t = 1;t < num[i];t++){
    if(p[k-num[i]+t].score == p[k-num[i]+t-1].score)
    p[k-num[i]+t].qunci = p[k-num[i]+t-1].qunci  ;
    else
    p[k-num[i]+t].qunci = t+1;
   // printf("%s %d %d %d\n",p[k-num[i]+t].id,p[k-num[i]+t].zci,p[k-num[i]+t].qunid,p[k-num[i]+t].qunci);
  }
}
/*printf("001\n");
for(i = 0;i < k;i++){
  printf("%s %d %d %d\n",p[i].id,p[i].zci,p[i].qunid,p[i].qunci);
}
*/
std::sort(p,p+k-1,sss);
/*printf("002\n");
for(i = 0;i < k;i++){
  printf("%s %d %d %d\n",p[i].id,p[i].zci,p[i].qunid,p[i].qunci);
}*/
p[0].zci = 1;
for(i = 1;i < k;i++){
   if(p[i].score == p[i-1].score){
     p[i].zci = p[i-1].zci;
   }
   else
     p[i].zci = i+1;
}
printf("%d\n",k);
for(i = 0;i < k;i++){
  printf("%s %d %d %d\n",p[i].id,p[i].zci,p[i].qunid,p[i].qunci);
}
}
