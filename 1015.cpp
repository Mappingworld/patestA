#include<cstdio>
#include<cmath>
int pprime(int a){
  int i = 0;
  //printf("&&&&");
  for(i = 2;i < (sqrt(a) + 1);i++){
   // printf("^^^^");
    if(a % i == 0)
        return 0;
  }
  return 1;
}
int rett(int a,int ret){
  int i = 0;
  char s[20];
  while(a != 0){
    s[i++] = a % ret;
    a = a / ret;
  }
  int t = 1;
  int b = 0;
  i --;
  while(i >= 0){
    b += s[i] * t;
    t *= ret;
    i --;
  }
  //printf("%d\n",b);
  return b;
}
int main(){
 int a = 0;
 int ret ;
 do{
    scanf("%d",&a);
    if(a < 0)
        return 0;
    else
      scanf("%d",&ret);
    // printf("OK\n");
    if(a == 1||pprime(a) == 0){
        printf("No\n");
    }
   // printf("OKKK\n");
   else{
    if(pprime(rett(a,ret)) == 1)
        printf("Yes");
    else
        printf("No");
    printf("\n");
   }
 }while(1);

}
