// m[i].child[j] = k;vector不可以直接赋值吗，好像只可以用push_back的，set是用insert，string是用+=，map使用a["KKKK"] = 0;
//如果要使用下标访问vector时，需要指定空间
#include<cstdio>
#include<vector>
#include<vector>
using namespace std;
double yuan;
double rate;
const int MAXI = 100000;
struct p{
  int data;
  vector<int> child;
}m[MAXI];
double sum = 0.0;
double biantree(int b,double chen){
  int i = 0;
  struct p a = m[b];
  //printf("chen %lf\n",chen);
  if(a.child.size() == 0){

    chen *= a.data;
   // printf("%lf %d\n",chen,a.data);
    sum += chen;
    return chen;
  }
  else
    for(vector<int>::iterator it = a.child.begin();it != a.child.end();it++){
       biantree(*it,chen *(1 + rate * 0.01));
      //printf("sum = %lf\n",sum);
    }
    return sum;
}

int main(){
 int i = 0;
 int num ;
 int k;
 int a;
 int j = 0;
 scanf("%d %lf %lf",&num,&yuan,&rate);
 for(i = 0;i < num;i++){
   scanf("%d",&a);
   if(a == 0){
     scanf("%d",&a);
     m[i].data = a;
   }
   else{
     for(j = 0;j < a;j++){
       scanf("%d",&k);
       //m[i].child[j] = k;
      m[i].child.push_back(k);
     }
   }

 }
 biantree(0,1.0);
  printf("%.1lf",sum * yuan);
}
