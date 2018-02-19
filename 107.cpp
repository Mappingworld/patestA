#include<cstdio>
#include<algorithm>
const int N = 10010;
struct m{
int ti[5];
int id;
int fulls;
int sig;
int zong;
}p[N];

bool pp(m a,m b){
  if(a.zong != b.zong)
    return a.zong > b.zong;
  if(a.fulls != b.fulls)
    return a.fulls > b.fulls;
  else
     return a.id < b.id;
}

int main(){
  int pnum;
  int tnum;
  int tcnum;
  int i , j;
  int a, b, c;
  int tis[5] = {0};
  scanf("%d %d %d",&pnum,&tnum,&tcnum);
  for(i = 0;i < tnum;i++){
    scanf("%d",&tis[i]);
  }
  for(i = 0;i < N;i++){
    for(j = 0;j < 5;j++){
       p[i].ti[j] = -1;
    }
  }
  for(i = 0;i < tcnum;i++){
    scanf("%d %d %d",&a,&b,&c);
    p[a].id = a;
  if(c == tis[b-1] && p[a].ti[b-1] != tis[b-1]){
      printf("%d %d %d\n",i,p[a].id,p[a].ti[b-1]);
      p[a].fulls ++;
    }
    if(p[a].ti[b-1] <= c){
      p[a].sig = 1;
      p[a].ti[b-1] = c;
    }

    if(c == -1&&p[a].ti[b-1] == -1){
        p[a].ti[b-1] = -2;
    }
  }

  for(i = 0;i < N;i++){
    if(p[i].sig == 1){
     for(j = 0;j < tnum;j++){
        if(p[i].ti[j] == -1 || p[i].ti[j] == -2)
          p[i].zong +=  0;
        else
          p[i].zong += p[i].ti[j];
     }
    }
  }
  std::sort(p,p+N,pp);
int u1 = 1;int u2 = 1;

  for(i = 0;i < N;i++){//等级排名
    if(p[i].sig == 1 && p[i].zong != 0){
      printf("%d ",u1);
     if(p[i].zong != p[i+1].zong){
        u1 = i+2;
     }


     printf("%05d %d",p[i].id,p[i].zong);
     for(j = 0;j <tnum;j++){
        if(p[i].ti[j] == -1){
            printf(" -");
        }
        else
            if(p[i].ti[j] == -2){
              printf(" 0");
             }
             else
               printf(" %d",p[i].ti[j]);
     }
     printf(" %d",p[i].fulls);
     printf("\n");
    }

  }


}
