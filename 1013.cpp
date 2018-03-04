//memset的头文件是cstring
#include<cstdio>
#include<vector>
#include<cstring>
const int MAXI = 1000;//1000
using namespace std;
vector<int>wux[MAXI];
bool sig[MAXI];

void dfs(int a,int k){
 int i = 0;
 int mx = wux[a].size();
 if(mx == 0)
   return ;
 for(i = 0;i < mx;i++){
   if(sig[wux[a][i]] != true && wux[a][i] != k){
      sig[wux[a][i]] = true;
      dfs(wux[a][i],k);
   }
 }
}

int main(){
int num;
int lu;
int shan;
scanf("%d %d %d",&num,&lu,&shan);
int i = 0;
int a = 0;
int b = 0;
for(i = 0;i < lu;i++){
  scanf("%d %d",&a,&b);
  wux[a].push_back(b);
  wux[b].push_back(a);
}
int m = 0;
int j = 0;
for(i = 0;i < shan;i++){
  scanf("%d",&a);
  memset(sig,false,sizeof(sig));//用memst进行全局赋值
  m = 0;

  for(j = 1;j <= num;j++){
    if(j != a && sig[j] == false){
      sig[j] = true;
      dfs(j,a);
      m++;
    }
  }
   printf("%d\n",m - 1);
}


}
