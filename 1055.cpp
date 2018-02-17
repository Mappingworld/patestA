#include<cstdio>
#include<cstring>
#include<algorithm>
const int N = 100000;
struct p{
 char name[10];
 int age;
 int men;
}m[N];
struct pn{
  int pnum;
  int stag;
  int ensg;
}M[1000];
bool prt(p a,p b){
  if(a.men != b.men){
    return a.men > b.men;
  }
  if(a.age != b.age){
    return a.age < b.age;
  }
  return strcmp(a.name,b.name) < 0;
}
int main(){
  int mun,pun;
  scanf("%d %d",&mun,&pun);
  int i = 0;
  for(i = 0;i < mun;i++){
    scanf("%s %d %d",m[i].name,&m[i].age,&m[i].men);
  }
  for(i = 0;i < pun;i++){
    scanf("%d %d %d",&M[i].pnum,&M[i].stag,&M[i].ensg);
  }
  std::sort(m,m+mun,prt);
  int f = 0,j=0;
  for(i = 0;i < pun;i++){
     printf("Case #%d:\n",i+1);
     for(j = 0;j < mun;j++){
       if(m[j].age >= M[i].stag && m[j].age <= M[i].ensg && M[i].pnum > 0){
         printf("%s %d %d\n",m[j].name,m[j].age,m[j].men);
         M[i].pnum --;
         f = 1;
       }
     }
     if( f == 0)
       printf("None\n");
     else
       f = 0;
  }
}
