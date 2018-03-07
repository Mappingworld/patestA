//对于不是连续的点，下次需要进行标号
//请特别注意不让之后修改会很花时间
//这一题的第一个选项要求输出的是距离最小的路径条数，而不是路径最小。快乐最多的条数，

#include<cstdio>
#include<map>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<iostream>
const int MAXI = 300;
const int INF = 1000000000;
using namespace std;
map<string ,int>s;//除了了map,或者将字符串转化成数字，还可以建立对应的字符串数组，用于标记
map<int ,string>q;
int happ[MAXI];
int cnum,lnum;
int lian[MAXI][MAXI];
int shor[MAXI];
bool flg[MAXI];
vector<int> qian[MAXI];
int happy[MAXI];//最大的快乐
int y[MAXI];
void bijk(int st){
  fill(shor,shor + MAXI, INF);
  qian[st].push_back(-1);
  memset(flg,false,sizeof(flg));
 // memset(qian,-1,sizeof(qian));
  y[st] = 1;
  shor[st] = 0;
  happy[st] = 0;
  int i,k;
  for(k = 0;k < cnum;k++){
    int mini = INF;
    int u = -1;
    for(i = 0;i < cnum;i++){
      if(flg[i] == false && shor[i]!= INF ){
          if(shor[i] < mini){
             mini = shor[i];
             u = i;
          }
      }
    }

    //printf("选定的数为%d\n",u);
    if(u == -1)
        return;
   //printf("进行检测\n");
   for(i = 0;i < cnum;i++){
   // printf("%d ",y[i]);
   }
    flg[u] = true;
    //printf("\n接下来是对相关的数进行修改\n");
    for(i = 0;i < cnum;i++){
        if(lian[u][i] != INF && flg[i] == false){
           // printf("y[%d] = %d",i,y[i]);
            //printf("y[%d] = %d\n",i,y[i]);
            if(lian[u][i] +shor[u] < shor[i]){
                 y[i] = y[u];
                shor[i] = lian[u][i] + shor[u];
                qian[i].clear();//建立树
                qian[i].push_back(u);
                happy[i] = happy[u] + happ[i];
            }else if(lian[u][i] + shor[u] == shor[i]){
      //               printf("进行合并\n");
                     y[i] = y[i] + y[u] ;
 //                    printf("y[%d] = %d",i,y[i]);
                     if(happy[i] < happy[u] + happ[i]){
                        qian[i].clear();//建立树
                        qian[i].push_back(u);
                        happy[i] = happy[u] + happ[i];
                     }else if(happy[i] == happy[u] + happ[i])
                           qian[i].push_back(u);

                     //qian[i].push_back(u);
            }
        }
    }
  }
}
//int time = 1;
int ni = INF;//表示最短层
vector<int> mm;//用于存储路径
vector<int> nn;//用于临时存储
void treep(int st,int ceng){
   nn.push_back(st);
   int i,j;
   if(qian[st][0] == -1){
    if(ceng < ni){
        ni = ceng;
        mm.clear();

        for(i = 0;i < nn.size();i++){
            mm.push_back(nn[i]);
        }
    }
    return;
   }
//    time *= qian[st].size() ;
   for(j = 0;j < qian[st].size();j++){
    treep(qian[st][j],ceng + 1);
   }
}

int main(){
 string ss;
 string st;
 scanf("%d %d",&cnum,&lnum);
 cin >> st;
 s[st] = 0;
 q[0] = st;
 int i , d;
 for(i = 1;i < cnum;i++){
    cin >> ss;
    cin >> d;
    s[ss] = i;
    q[i] = ss;
    happ[i] = d;
 }
 string sss;
 fill(lian[0],lian[0] + MAXI * MAXI,INF);
 for(i = 0;i < lnum;i++){
    cin >> ss >> sss >> d;
    lian[s[ss]][s[sss]] = d;
    lian[s[sss]][s[ss]] = d;
 }
 bijk(0);
 //printf("最大快乐为：%d\n",happy[s["ROM"]]);
 //printf("最短路径为： %d\n",shor[s["ROM"]]);
 //printf("建树完成，接下来打印树\n");
 i = s["ROM"];
 int j = 0;
 for(i = 0;i < cnum;i++){
   // printf("%d:",i);
    for(j = qian[i].size() - 1;j >= 0;j--){
     //  printf("%d ",qian[i][j]);
    }
   // printf("\n");
 }
 //printf("接下来进行深度遍历,找出最短层数\n");
 treep(s["ROM"],1);
 //printf("遍历结束，接下来反向输出结果\n");
 //printf("最小层数为：%d",ni);
 //printf("\n最短路径为：");
 for(i = 0;i < mm.size();i++){
   // printf("%d ",mm[i]);
 }
 //printf("\n");
 int a;
 printf("%d %d %d %d\n",y[s["ROM"]],shor[s["ROM"]],happy[s["ROM"]],happy[s["ROM"]] / (mm.size() - 1));
 cout << q[0];
 for(i = mm.size() - 2;i >= 0;i--){
    a = mm[i];
    cout << "->"<<q[a];
 }
 //printf("\n");
}


