//两数最大公约数，必然是除数与余数的最大公约数，因此用递归
//其中数组使用long long 建立二位数时候，无法使用
//有一个测试点迟迟通不过，前面考虑可能是因为负数问题后来发现，似乎是在每次通分后的累计没有及时约分导致的感觉这个有点恐怖

#include<cstdio>

int gcd(int a,int b){//求解最大公约数
   if(b == 0)
      return a;
    else
      return gcd(b,a%b);

}
int main(){
  int num ;
  int i = 0;
  int s[2][102];
  long long re = 1;
  int e = 0;
  scanf("%d",&num);
  for(i = 0;i < num;i++){
    scanf("%d/%d",&s[0][i],&s[1][i]);
  }
  for(i = 0;i < num;i++){
    //printf("%d/%d",s[0][i],s[1][i]);
  }
  for(i = 0;i < num;i++){
    if(re % s[1][i] != 0){
        //printf("s[1][%d] = %d\n",s[1][i]);
        e = gcd(re,s[1][i]);
       // printf("%d * = (%d / %d)\n",re,s[1][i],e);
        re *= (s[1][i] / e);
       // printf("re = %d\n",re);
    }

  }
 // printf("%d\n",re);
  long long  es = 0;
  for(i = 0;i < num;i++){
    es += re / s[1][i] * s[0][i];
  }

  if(es * re < 0)
    printf("-");
  if(es < 0)
    es = - es;
  if(re < 0)
    re = - re;
  int m = es / re;
  if(m != 0)
    printf("%d",m);
   int t = es % re;
   if(t != 0){
      if(m != 0)
        printf(" ");
      e = gcd(re,t);
     printf("%ld/%ld",t/e,re/e);
   }else{
     if(m == 0){
       printf("0");
     }
   }
}
