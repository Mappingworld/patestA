//在思路没有问题时，有大部分的测试用例没有通过可以看看是不是题目没有看全
#include<cstdio>
#include<vector>

using namespace std;
const int MAXI = 100000;
vector<int> m[MAXI];
int num;
int litt;
double yuan;
int f = 0;
double rate;
void treecen(int a,int ce){
  ce++;
  if(m[a].size() == 0){
    //printf("ce =%d \n",ce);
    if(ce == litt){
        f ++;
    }
    if(ce < litt){
      litt = ce;
     // printf("litt = %d\n",litt);
      f = 1;
    }

  }
  for(vector<int>::iterator it = m[a].begin();it != m[a].end();it++){
     treecen(*it,ce);
  }
}
int main(){
  int i = 0;
  int j = 0;
  int h = 0;
  int a;
  scanf("%d %lf %lf",&num,&yuan,&rate);
  for(i = 0;i < num;i++){
    scanf("%d",&h);
    for(j = 0;j < h;j++){
      scanf("%d",&a);
      m[i].push_back(a);
    }
  }
   litt = num;
   treecen(0,0);

   double u = yuan;
   for(i = 0;i < litt - 1;i++){
     u = u *(1 + rate/100);
   }
   printf("%.4lf",u);
    printf(" %d",f);
}
