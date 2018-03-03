#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
const int MAXI = 100;
struct p{
  vector<int> m;
}s[MAXI];

int level[MAXI];
void treeguan(int a,int k){
 level[k]++;
 struct p b = s[a];
 for(vector<int>::iterator it = b.m.begin();it != b.m.end();it++){
   treeguan(*it,k+1);
 }
}

int main(){
  int num;
  int hasc;
  scanf("%d %d",&num,&hasc);
  int i ,j= 0;
  int a, b, c;
  for(i = 0;i < hasc;i++){
    scanf("%d %d",&a,&b);
    for(j = 0;j < b;j++){
     scanf("%d",&c);
     s[a].m.push_back(c);
    }
  }
  treeguan(1,1);
  int maxy = -1;
  int id = -1;
  for(i = 0;i < num;i++){
     if(level[i] > maxy){
         maxy = level[i];
         id = i;
     }

  }
   printf("%d %d",maxy,id);
}
