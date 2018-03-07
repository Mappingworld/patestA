#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXI = 10009;
const int MAXII = 109;
bool qq(int a,int b){
  return a > b;
}
int main(){
  int m[MAXI];
  int m1[MAXII][MAXII];
  int num;
  scanf("%d",&num);
  int i = 0;
  for(i = 0;i < num;i++){
    scanf("%d",&m[i]);
  }
  //intf("OK\n");
  int j = 0;
  for(i = 1;i <= (sqrt(num) + 1);i++){
    if(num %i == 0){
      j = i;
    }
  }
  int cos = j;
  int clu = num / j;
 // printf("da %d xiao%d\n",cos,clu);
  if(num == 2){
     cos = num / j;
   clu = j;
  }
  //建一个二维数组将值输入
  sort(m,m + num,qq);
  //printf("sort OK\n");
  j = 0;
  int u = 0;
  int k = clu;
  int r = cos;
  u = 0;
  i = 0;
int  f = -1;
int cl = clu;
  int s = -1;
  while(j != num){

     for(i = ++f;i < cl&&j != num;i++){
       m1[u][i] = m[j++];
      // printf("%d !",m1[u][i]);
     }
     cl --;
    // printf("\n");
     i --;
     for(u++;u < r &&j != num;u++){
       m1[u][i] = m[j++];
     //  printf("u[%d][%d]%d !",u,k,m1[u][k]);
     }
     k = i;
     //printf("\n");
     r --;
     u --;
     for(i = --k;i > s&&j != num;i--){
        m1[u][i] = m[j++];
       // printf("%d !",m1[u][i]);
     }
     //printf("\n");
     s ++;
     i ++;
     for(--u;u > f&&j != num;u --){
        m1[u][i] = m[j++];
       // printf("u[%d][%d] %d !",u,i,m1[u][i]);
     }
     //printf("\n");
     u ++;
     //printf("OOK\n");
  }
  //printf("OVER\n");
  for(i = 0;i < cos;i++){
    printf("%d",m1[i][0]);
    for(j = 1;j < clu;j++){
     printf(" %d",m1[i][j]);
    }
    printf("\n");
  }
}
