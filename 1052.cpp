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
