#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
const int MAXI = 20;
const int INF = 1000000000;
int weight[MAXI];
int d[MAXI];//记录最短距离
int cc[MAXI];//最短路径的条数
int dd[MAXI];//路径上的最大人数
int l[MAXI][MAXI];
bool flg[MAXI];
int num = 0;
void dijik(int st){
  fill(d,d + MAXI,INF);
  memset(cc,0,sizeof(cc));
  memset(dd,0,sizeof(dd));

  d[st] = 0;
  cc[st] = 1;
  int i ,j = 0;
  dd[st] = weight[st];
  for(i = 0;i < num;i++){
    int mini = INF;
    int u = -1;
    for(j = 0;j < num;j++){
      if(d[j] < mini && flg[j] == false){//将未划分的进行最小值的筛选
        mini = d[j];
        u = j;
      }
    }
    if(u == -1){
      return ;
    }
    flg[u] = true;//接下来就是对相关节点的属性值进行修改
    for(j = 0;j < num;j++){
      if(flg[j] == false && l[u][j] != INF){
         if(l[u][j] + d[u] < d[j]){
           d[j] = l[u][j] + d[u];
           dd[j] = weight[j] + dd[u];
           cc[j] = cc[u];
         }else if(l[u][j] + d[u] == d[j]){
          if(dd[j] < weight[j] +dd[u]){
           dd[j] = weight[j] +dd[u];
          }
          cc[j] += cc[u];//最大路径条数不是仅仅加一
        //  printf("j= %d %d %d\n",j,cc[j],cc[u]);
         }

      }
    }
  }

}
int main(){
int lu,st,en;
int i = 0;
scanf("%d %d %d %d",&num,&lu,&st,&en);
for(i = 0;i < num;i++){
  scanf("%d",&weight[i]);
}
//printf("OOOOOOOOOk1\n");
memset(flg,false,sizeof(flg));
//printf("OOOOOOOOOk1\n");
int a,b,c;
fill(l[0],l[0] + MAXI * MAXI,INF);//这里关于fill的使用
//printf("OOOOOOOOOOOOk2\n");
for(i = 0;i < lu;i++){
  scanf("%d %d %d",&a,&b,&c);
  l[a][b] = c;
  l[b][a] = c;
}
dijik(st);
printf("%d %d",cc[en],dd[en]);
}
