#include<cstdio>
const int N = 100000;
struct p{
 int next;
 int data;
}k[N];
int main(){
  int i = 0;
  int f = 0;
  int e = 0;
  int num = 0;
  char r ;
  int a = 0;
  int b = 0;
  scanf("%d %d %d",&f,&e,&num);
  for(i = 0;i < num;i++){
    scanf("%d %c %d",&a,&r,&b);
    k[a].next = b;
  }
  i = f;
  k[i].data = 1;
  while(k[i].next != -1){
    i = k[i].next;
    k[i].data = 1;
  }
  i = e;
  int flg = 0;
  if(k[i].data == 1){
    flg = 1;
  }
  else
  while(k[i].next != -1){
    i = k[i].next;
    if(k[i].data == 1){
        flg =1;
        break;
    }
  }
  if(flg == 1){
    printf("%05d",i);
  }
  else
    printf("-1");
}
