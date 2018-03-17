#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXI = 10010;
vector<int> m[MAXI];
bool f[MAXI];
int xx[MAXI];
int ceng[MAXI] ;
vector<int>mm[2];
void def(int a){
  //printf("a = %d\n",a);
  int i = 0;
  f[a] = true;
  int se = m[a].size();
  for(i = 0;i < se;i++){
    if(f[m[a][i]] == false)
    def(m[a][i]);
  }
}
void dfs(int a,int ce){
    int i = 0;
 // printf("a = %d, ce = %d\n",a,ce);
  int k = m[a].size();
  ceng[a] = ce;
  f[a] = true;
  for(i = 0;i < k;i++){
    if(f[m[a][i]] == false )
     dfs(m[a][i],ce + 1);
  }
}


int main(){
int num ;
int i;
scanf("%d",&num);
int a,b;
for(i = 0;i < num - 1;i++){
 scanf("%d %d",&a,&b);
 m[a].push_back(b);
 m[b].push_back(a);
}
//树已经建好
//printf("进行图的连通性的判断\n");
memset(f,false,sizeof(f));
int time = 0;
for(i = 1;i <= num;i++){
  if(f[i] != true){
   // printf("fei%d",i);
    def(i);
    time ++;
  }
}
if(time != 1){
  printf("Error: %d components",time);
  return 0;
}
memset(f,false,sizeof(f));
//判断完成，进行最高顶点的寻找，规则从任意点出发找到，最深的点集合，再从点集中任意一点找到最深点
dfs(1,0);
int ma = -1;
int leng = 0;
for(i = 1;i <= num;i++){
    if(ceng[i] > ma){
        ma = ceng[i] ;
        mm[0].clear();
        mm[0].push_back(i);
    }
    else
        if(ceng[i] == ma){
        mm[0].push_back(i);
    }
}
int w = mm[0].size();
for(i = 0;i < w;i++){
   // printf("%d  ",mm[0][i]);
}
//printf("\n");
memset(ceng,0,sizeof(ceng));
memset(f,false,sizeof(f));
dfs(mm[0][i - 1],0);
ma = -1;
for(i = 1;i <= num;i++){
   // printf("%d ",ceng[i]);
}
for(i = 1;i <= num;i++){
    if(ceng[i] > ma){
        ma = ceng[i];
        mm[1].clear();
        mm[1].push_back(i);
    }
    else
        if(ceng[i] == ma){
        mm[1].push_back(i);
    }
}
 w = mm[1].size();
for(i = 0;i < w;i++){
   // printf("%d  ",mm[1][i]);
}
//printf("\n");
//寻找共有的元素
int j = 0;
for(i = 0;i < mm[0].size();i++){
    xx[j++] = mm[0][i];
}
for(i = 0;i < mm[1].size();i++){
    xx[j++] = mm[1][i];
}
sort(xx,xx + j);
for(i = 0;i < j;i++){
    printf("%d\n",xx[i]);
}
}
