#include<cstdio>
//Long Long 在使用时要注意初始化为0，不然很容易高位不为0
long long a = 0;
long long b = 0;
int panduan(long long c){
  int  i = 0;
 // printf("c  = %ld",c);
  while(c != 0){
    i ++;
    c = c / 10;
   //  printf("c  = %ld\n",c);
  }
  //printf("weishu :%d\n",i);
  return i ;
}
void disb(long long c){
  int wei1 = panduan(c);
  int i = 0;
  long long m = 1;
  for(i = 0;i < wei1 / 2;i++){
     m *= 10;
  }
  //printf("m = %ld",m);
  a = c % m;
  b = c / m;
}

int main(){
  int i = 0;
  int num = 0;
  scanf("%d",&num);
  long long  test = 0;
  for(i = 0;i < num;i++){
    scanf("%ld",&test);
    disb(test);
    if(a * b == 0){
        printf("No\n");
    }else
    if(test % (a * b) == 0){
      printf("Yes\n");
    }else{
      printf("No\n");
    }
  }

}
