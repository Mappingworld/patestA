/*
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 100009;
struct m{
  int data;
  int next;
  int x;
  int add;
} n[N];
bool qq(m a,m b){
  if(a.x == 2&& b.x == 2)
    return a.data < b.data;
  else
    if(a.x != 2)
    return false;
  else
    if(b.x != 2)
     return true;
}
int main(){
  int i = 0;
  int num = 0;
  int sta;
  int y = 0;
  int h;
  int dd;
  scanf("%d %d",&num,&sta);
  for(i = 0;i < num;i++){
    scanf("%d %d %d",&y,&h,&dd);
    n[y].data = h;
    n[y].next = dd;
    n[y].x = 1;
    n[y].add = y;
  }
  i = sta;
  n[i].x = 2;
  int p = 1;
  while(n[i].next != -1){
    i = n[i].next;
    n[i].x = 2;
    p ++;
  }
  sort(n,n+N,qq);
  for(i = 0;i < num - 1;i++){
    n[i].next = n[i + 1].add;
  }
  n[i].next = -1;
  printf("%d %05d\n",p,n[0].add);
  for(i = 0;i < p;i++){
    printf("%05d %d ",n[i].add,n[i].data,n[i].next);
    if(i < p - 1){
        printf("%05d\n",n[i].next);
    }
    else
        printf("-1");
  }
}
*/
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXI = 100000;
int s[MAXI] ;
int aa[MAXI][2];

bool qq(int a,int b){
  return aa[a][0] < aa[b][0];
}
int main(){
   int num ;
   int fir;
   int i = 0;
   int a,b,c;
   scanf("%d %d",&num,&fir);
   for(i = 0;i < num;i++){
     scanf("%d %d %d",&a,&b,&c);
     aa[a][0] = b;
     aa[a][1] = c;
   }
   //printf("read finished\n");
   int r = fir;
   i = 0;
   while(r != -1){
     s[i ++] = r;
     r = aa[r][1];
   }
   //printf("will sort\n");
   sort(s,s + i ,qq);
   printf("%d %05d\n",i,s[0]);
   int  j = 0;
   int flg = 0;
   for(j = 0;j < i;j++){
     if(flg == 0){
       printf("%05d %d ",s[j],aa[s[j]][0]);
       flg = 1;
     }
     else
       printf("%05d\n%05d %d ",s[j],s[j],aa[s[j]][0]);
   }
   printf("-1");
}
