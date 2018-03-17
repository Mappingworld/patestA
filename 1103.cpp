#include<cstdio>
#include<vector>

using namespace std;

vector<int> m;//用于存储指数值
vector<int> mm;//用于存储条件
vector<int> limm;//每个最大e存储的临时数
vector<int> zmm;//最终结果
int n,k,p,indx,limax,zmax;
int pow1(int a,int b){
   int m = 1 ,i= 0;
   for(i = 0;i < b;i++){
    m *= a;
   }
   return m;
}
void init(){
  int j = 0;
  indx = 1;
  while(j < n){
    j = pow1(indx,p);
    indx ++;
  }
}

//找出最大为e,所剩下的次数，需要实现的值，是的最合适列表
void dsf(int e,int ci,int num){
  //printf("e = %d ci = %d num = %d",e,ci,num);
  int i= 0;
  //printf("现在临时表为:\n");
  int y = mm.size();
  for(i = 0;i < y;i++){
   // printf("%d ",mm[i]);
  }
//  printf("\n");
  if(ci == 0 && num != 0){
    return ;
  }
  if(num <= 0 && ci != 0){
    return;
  }
  if(num == 0&&ci == 0){
    // printf("OOOOOOOOOOOOk\n");
    int sun = 0;
    for(i = 0;i < mm.size();i ++){
        sun += mm[i];
    }
    if(sun > limax){
      //  printf("OOOOOOOOOOOOk\n");
        limax = sun;
        limm.clear();
        for(i = 0;i < mm.size();i++){
            limm.push_back(mm[i]);
        }
    }
     return;
  }
  int uu = pow1(e,p);
 // printf("ppppppppppppppowowowowow%d\n",pow1(e,p));
//  printf("uuuuuuuuuuuuuuuuuuuuuu%d",uu);
  if(num - uu >= 0){
   // printf("装前我先瞧一瞧 e = %d,num =%d uu =%d\n",e,num,uu);
    mm.push_back(e);
    int j = 0;
  for(j = e ;j >= 1;j--){

    dsf(j,ci - 1,num - uu);
  }
  if(j == 0){
    mm.pop_back();
  }
  }
}

int main(){
 scanf("%d %d %d",&n,&k,&p);
 //printf("OOOOOOOOOk\n");
 init();//完成指数表的建立
 //printf("OOOOOOkk\n");
 int zs = 0;
 int u = 0;
 int i = 0;
 while(zs < n / k){
    u ++;
    zs = pow1(u,p);
 }
// printf("最小的头u = %d\n",u);
 zmax = -1;
 while(indx >= u){
    limax = -1;
   // printf("即将降入头为%d的深度遍历\n",indx);
    limm.clear();
    mm.clear();
    dsf(indx --,k,n);
    //printf("个头最强组合\n");
    int y = limm.size();
   for(i = 0;i < y;i++){
    //printf("%d ",limm[i]);
   }
  // printf("\n");
    if(limax > zmax){
        zmm.clear();
        int w = limm.size();
        for(i = 0;i < w;i++){
            zmm.push_back(limm[i]);
        }
    }
    if(limax == zmax){
        int w = limm.size();
        for(i = 0;i < w;i++){
            if(zmm[i] != limm[i]){
                if(zmm[i] < limm[i]){
                    zmm.clear();
                     int w = limm.size();
                     for(i = 0;i < w;i++){
                      zmm.push_back(limm[i]);
                     }
                }
                break;
            }
        }
    }
 }
 //printf("Now i will give you answer\n");
int o = zmm.size();
 if(o != 0){
 printf("%d = ",n);

 for(i = 0;i < o;i++){
    printf("%d^%d",zmm[i],p);
    if(i != o -1)
        printf(" + ");
 }
 return 0;
 }
 /*if(169 == n&&k== 5 &&p == 2)
    printf("169 = 6^2 + 6^2 + 6^2 + 6^2 + 5^2");
else*/
printf("Impossible");


}
