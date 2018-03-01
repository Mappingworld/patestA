#include<cstdio>
#include<set>

using namespace std;
set <int> q;
const int MAXI = 100009;
struct p{
  int addr;
  int next;
  int data;
  int x;
}m[MAXI];

int main(){
  int st;
  int num;
  int ji;
  int a,b,c;
  int i ;
  scanf("%d %d",&st,&num);
  for(i = 0;i < num;i++){
    scanf("%d %d %d",&a,&b,&c);
    m[a].addr = a;
    m[a].data = b;
    m[a].next = c;
    if(b < 0)
      b = -b;
    if(q.find(b) != q.end()){
       m[a].x = 2;
       ji++;
    }
    else
      q.insert(b);//函数名称忘记了，得看看
  }
  int j = 1;
   i = st;
  printf("%05d %d ",m[i].addr,m[i].data);
  i = m[i].next;
  int u = 1;
  int y = -1;
  while(i != -1){
    if(m[i].x != 2){
        printf("%05d\n",m[i].addr);
        printf("%05d %d ",m[i].addr,m[i].data);
    }
   j++;
   if(m[i].x == 2&&u == 1){
     y = i;
     u --;
   }
   i = m[i].next;
  }
  printf("-1\n");
  i = y;
  if(y != -1){
  j = 0;

  printf("%05d %d ",m[i].addr,m[i].data);
  i = m[i].next;
  while(i != -1){//特别注意在结构体中得这一步循环while(m[i].next != -1)
    if(m[i].x == 2){
        printf("%05d\n",m[i].addr);
        printf("%05d %d ",m[i].addr,m[i].data);
    }
    i = m[i].next;
  }
  printf("-1\n");
}
}
