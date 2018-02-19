#include<cstdio>
#include<algorithm>
struct p{
  int score;
  char id[12];
  char name[12];
}st[120];
bool pp(p a,p b){
 return a.score > b.score;
}
int main(){
int i = 0;
int num;
scanf("%d",&num);
for(i = 0;i < num;i++){
  scanf("%s %s %d",st[i].name,st[i].id,&st[i].score);
}
int low,high;
scanf("%d %d",&low,&high);
std::sort(st,st+num,pp);
int f = 0;
for(i = 0;i < num;i++){
   if(st[i].score >= low&&st[i].score <= high){
     printf("%s %s\n",st[i].name,st[i].id);
     f = 1;
   }
}
if(f == 0)
  printf("NONE");
return 0;
}
