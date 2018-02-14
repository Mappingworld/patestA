#include<cstdio>
#include<algorithm>
const int N = 10;
int sig = 0;//全局变量用来表示进行排序的对象
struct st{
int ci[5];
int id;
int c;
int m;
int e;
double a;
int bid;
}p[N];

int stu[2][N]={0};

char re[4] = {'A','C','M','E'};

bool cmp(st a1,st b1){
  if(sig == 1){
     return a1.a > b1.a;
  }
  if(sig == 2){
     return a1.c > b1.c;
  }
  if(sig == 3){
     return a1.m > b1.m;
  }
  if(sig == 4){
     return a1.e > b1.e;
  }
  if(sig ==5){
    return a1.bid < b1.bid;
  }
}

int main(){
  int a,b;
  scanf("%d %d",&a,&b);

  int i = 0;
  for(i = 0;i < a;i++){
     scanf("%d %d %d %d",&p[i].id,&p[i].c,&p[i].m,&p[i].e);
     p[i].a = (p[i].c + p[i].m + p[i].e) / 3.0;
  }
  for(i = 0;i < b;i++){
    scanf("%d",&stu[0][i]);
    stu[1][i]=i;
  }
  int f,j =0;
   for(i = 0;i < b;i++){
    for(j = 0;j < a;j++){
      if(p[j].id == stu[0][i]){
         p[j].bid = stu[1][i];
         f = 1;
      }
    }
    if( f == 1){
      stu[1][i] = -1;//-1表存在
      f = 0;
    }
   }

  for(i = 0;i < 4;i++){
     sig++;
     std::sort(p,p+a,cmp);
     for(j = 0;j < a;j++){
       p[j].ci[i] = j+1;
     }
  }

  //for(i = 0;i < a;i++){
    //printf("%d %d %d %d %d\n",p[i].id,p[i].ci[0],p[i].ci[1],p[i].ci[2],p[i].ci[3]);
  //}
  sig++;
  std::sort(p,p+a,cmp);

  //for(i = 0;i < a;i++){
    //printf("%d %d %d %d %d\n",p[i].id,p[i].ci[0],p[i].ci[1],p[i].ci[2],p[i].ci[3]);
  //}
  int max = 0;
  int imax = 0;
  for(i = 0;i < a;i++){
     max = p[i].ci[0];
     imax = 0;
    for(j = 1;j < 4;j++){
      if(p[i].ci[j] < max){
        max = p[i].ci[j];
        imax = j;
      }
    }
    p[i].ci[0] = max;
    p[i].ci[1] = imax;
  }
//for(i = 0;i < a;i++){
  //  printf("%d \n",p[i].id);
//}

  j=0;
  for(i = 0;i < b;i++){
   if(stu[1][i] == -1){
     printf("%d %c\n" ,p[j].ci[0],re[p[j].ci[1]]);
     j++;
   }
   else
     printf("N/A\n");


  }
}
