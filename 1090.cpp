#include<cstdio>
#include<vector>
using namespace std;
const int MAXI = 100000;
struct p{
vector<int> s;
} q[MAXI];
double yuan;
double rate;
int num;
int maxp = 0;
int tim = 0;
void bianli(int b,int le){
   struct p w = q[b];
   if(w.s.size() == 0){
     if(maxp == le){
        tim ++;
     }
     if(maxp < le){
       maxp = le;
       tim = 1;
     }

//      printf("%d\n",tim);
   }
   for(vector<int>::iterator it = w.s.begin();it < w.s.end();it++){
     bianli(*it,le+1);
   }
 }
int main(){
  int i = 0;
  int a = 0;
  int b = 0;
  scanf("%d %lf %lf",&num,&yuan,&rate);
  for(i = 0;i < num;i++){
   scanf("%d",&a);
   if(a != -1)
    q[a].s.push_back(i);
   if(a == -1)
     b = i;
  }
  bianli(b,0);

  double ps = yuan;
  for(i = 0;i < maxp;i++){
    ps *= (1 + rate/100);
  }
  printf("%.2lf ",ps);
  printf("%d",tim);
}
