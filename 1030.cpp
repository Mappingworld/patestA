#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXI = 509;
const int INF = 1000000000;
int cnum,tnum,st,en;
int lu[MAXI][MAXI];//表示路径关系

bool fin[MAXI];//查看表示
int shor[MAXI];//表示最短路径
int cost[MAXI];//表示最小开销
int cosi[MAXI][MAXI];//表示路径开销
int qian[MAXI];
void jikp(int st){
  int i = 0;
  int j = 0;
  memset(qian,0,sizeof(qian));
  fill(shor,shor + MAXI,INF);
  fill(cost,cost + MAXI,INF);
  shor[st] = 0;
  cost[st] = 0;
  qian[st] = -1;
  for(i = 0;i < cnum;i++){
        //这一步是确定点
    int mini = INF;
    int u = -1;
    for(j = 0;j < cnum;j++){
        if(fin[j] == false && shor[j] != INF){
            if(mini > shor[j]){
                mini = shor[j];
                u =j;
            }
        }
    }
    if(u == -1){
        return;
    }
    fin[u] = true;
    //下部是将相关点的值进行更新
    for(j = 0;j < cnum;j++){
        if(lu[u][j] + shor[u] < shor[j] && fin[j] != true){
           shor[j] = lu[u][j] + shor[u];
           cost[j] = cosi[u][j] + cost[u];
           qian[j] = u;
        }else if(lu[u][j] + shor[u] == shor[j] && fin[j] != true){
            if( cost[j] > cosi[u][j] + cost[u]){
                cost[j] = cosi[u][j] + cost[u];
                qian[j] = u;
            }
        }
    }
  }

}


int main(){
int i = 0;
scanf("%d %d %d %d",&cnum,&tnum,&st,&en);
int a,b,c,d;
fill(lu[0],lu[0] + MAXI * MAXI,INF);
fill(cosi[0],cosi[0] + MAXI * MAXI,INF);
for(i = 0;i < tnum;i++){
  scanf("%d %d %d %d",&a,&b,&c,&d);
  lu[a][b] = c;
  lu[b][a] = c;
  cosi[a][b] = d;
  cosi[b][a] = d;
}
jikp(st);
i = en;
int k = 0;
int f[MAXI];
while(i != -1){
    f[k++] = i;
    i = qian[i];
}
for(i = k - 1;i >= 0;i--){
    printf("%d ",f[i]);
}
printf("%d %d",shor[en],cost[en]);
  return 0;
}
