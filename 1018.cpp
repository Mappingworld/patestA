#include<vector>
#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
const int inf = 99999999;
int e[510][510];//描述站站之间的关系
vector<int> fans[510];//所有最短路径
int weight[510];//站点的权重
int rig[510];//表示点到原点的最短距离
bool res[510];//表示已经确认的最终点
vector<int> temans;
vector<int> ans;
int findai = inf;
int finnn = inf;
void dfs(int a){
       temans.push_back(a);

       if(a == 0){
          int nn = 0;//表示当前所余
          int dai = 0;//表示需要带的车数
          for(int j = temans.size() - 2;j >= 0;j--){
              int i = temans[j];
              if(weight[i] > 0)
                nn += weight[i];
              if(weight[i] < 0){
                if(nn + weight[i] >= 0){
                    nn = nn + weight[i];
                }else{
                    dai += 0 - (nn + weight[i]);
                    nn = 0;
                }
              }
          }
          if(dai < findai){
              ans = temans;
              findai = dai;
              finnn = nn;
          }else{
            if(dai == findai && nn < finnn){
             ans = temans;
             finnn = nn;
            }
          }

          return;

       }

       for(int i = 0;i < fans[a].size();i++){
         dfs(fans[a][i]);
         temans.pop_back();
       }


}

int main(){
  int maxc,num,st,a,b,c,f;
  scanf("%d %d %d %d",&maxc,&num,&st,&a);
  fill(e[0],e[0] + 510 * 510,inf);
  fill(rig,rig + 510,inf);
  weight[0] = 0;
  for(int i = 0;i < num;i++){
    scanf("%d",&b);
    weight[i + 1] = b - maxc / 2;
  }
  //cout << "f1\n";
  for(int i = 0;i < a;i++){
    scanf("%d %d %d",&b,&c,&f);
    e[b][c] = f;
    e[c][b] = f;
  }
  //cout <<"f2\n";

  //进行最短路径的遍历

  rig[0] = 0;
  for(int i = 0;i <= num;i++){
    //查看第二类中最短点
    int u = -1;int mini = inf;
    for(int j = 0;j <= num;j++){
        if(res[j] == false && mini > rig[j]){
            u = j;
            mini = rig[j];
        }
    }
    if(u == -1){
        //cout << "f3\n";
        break;
    }
    //更新相关值
    res[u] = true;
    for(int j = 0 ;j <= num;j++){//特别注意等号
        if(res[j] == false){
            if(e[j][u] + rig[u] < rig[j]){
                rig[j] = e[j][u] + rig[u];
                fans[j].clear();;
                fans[j].push_back(u);
            }
            else{
                if(e[j][u] + rig[u] == rig[j]){
                 fans[j].push_back(u);
                }
            }
        }
    }

  }
  //cout <<"45678"<< fans[st][1];
  dfs(st);
/*
  cout << st << " " <<fans[st].size() << fans[st][2];
  int j = st;
  while(fans[j].size()){
    cout << " " << fans[j][0];
    j = fans[j][0];
  }
  */
   printf("%d 0", findai);
    for(int i = ans.size() - 2; i >= 0; i--)
        printf("->%d", ans[i]);
    printf(" %d", finnn);
    return 0;


}


