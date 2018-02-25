//这里输出时，存在问题，如果使用前一种输出会出现错误，下次尽量避免不要出现太有问题的书写
#include<cstdio>
#include<algorithm>
bool qq(int a,int b){
  return a > b;
}
void hua(int a,int b[]){
  int i , c =10;
  for(i = 0;i < 4;i++){
    b[i] = a % c;
    a = a/10;
  }
}
int he(int a[]){
   int i = 0,c = 1;
   int m = 0;
   for(i = 3;i >= 0;i--){
     m += a[i] * c;
      c *= 10;
   }
   return m;
}
int main(){
  int s = 0;
  scanf("%d",&s);
  int ss[4] = {0};
  int a = 0;
  int b = 0;
  do{
    hua(s,ss);
    std::sort(ss,ss+4,qq);
    a = he(ss);
   // printf("%d%d%d%d - ",ss[0],ss[1],ss[2],ss[3]);
    std::sort(ss,ss+4);
    b = he(ss);
    //printf("%d%d%d%d ",ss[0],ss[1],ss[2],ss[3]);
    printf("%04d - %04d = %04d\n",a,b,a-b);
    s = a - b;
  }while(s != 0 &&s != 6174);
  return 0;
}
