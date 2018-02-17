#include<cstdio>
#include<algorithm>
#include<cstring>
const int N = 1000;
struct p{
int id;
char name[10];
int score;
}st[N];
int t = 0;
bool qrt(p a,p b){
  if(t == 1){
    return a.id < b.id;
  }
  if(t == 2){
    if (strcmp(a.name,b.name) > 0)
      return 0;
    if (strcmp(a.name,b.name) < 0)
      return 1;
    else
      return a.id < b.id;
  }
  if(t == 3){
     if(a.score == b.score)
        return a.id < b.id;
     else
        return a.score > b.score;

  }
}
int main(){
 int i = 0;
 int num = 0;
 scanf("%d %d",&num,&t);
 for(i = 0;i < num;i++){
   scanf("%d %s %d",&st[i].id,st[i].name,&st[i].score);
 }
 std::sort(st,st+num,qrt);//[)
 for(i = 0;i < num;i++){
   printf("%06d %s %d\n",st[i].id,st[i].name,st[i].score);
 }
}
