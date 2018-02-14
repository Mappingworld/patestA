//1.题目理解起来费力 2.利用sort函数进行比较,std::sort(M,M+nu,cmp1);
//第一次提交 在比较中，对于分数相同，比较德
//第二次是空间不够大
//第三次是在划分第三类时，德大于等于才
#include<cstdio>
#include<algorithm>
const int N = 100020;
struct pe{
int id;
int v;//德
int c;
int k;
} M[N];

bool cmp1(pe a, pe b){
  if(a.k != b.k)
     return a.k < b.k;//a<b,把a放在前面
   int s1 = a.v + a.c;
   int s2 = b.v + b.c;
   if(s1 != s2)
      return  s1 > s2;
   else
      if(a.v != b.v)
        return a.v > b.v;
   return a.id < b.id;

}

int main(){
int nu;
int g;
int y;
scanf("%d %d %d",&nu,&g,&y);
int i = 0;int j=0;
for(i = 0;i < nu;i++){
  scanf("%d %d %d",&M[i].id,&M[i].v,&M[i].c);
  if(M[i].v >= y&&M[i].c >= y){
     M[i].k = 1;
  }
  else
    if(M[i].v >= y&&M[i].c >= g){
      M[i].k = 2;
    }
    else
      if(M[i].v < g||M[i].c < g){
        M[i].k = 5;
        j++;
      }
      else
        if(M[i].v >= M[i].c){
          M[i].k = 3;
        }
        else
          M[i].k = 4;
}

std::sort(M,M+nu,cmp1);

printf("%d\n",nu-j);
for(i = 0;i < nu;i++){
  if(M[i].k != 5)
  printf("%d %d %d\n",M[i].id,M[i].v,M[i].c);
}

return 0;

}
