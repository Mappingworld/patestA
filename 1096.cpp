#include<cstdio>
#include<cmath>
int main(){
  int num;
  scanf("%d",&num);
  int len = 0;
  int maxi = 0;
  int x = 0;
  int r = num;
  int i = 0,j = 0;
  for(i = 2;i < sqrt(num) + 1;i++){
    r = num;
    for(j = i;j < sqrt(num) + 1;j++){
      //printf("j = %d\n",j);
      if(r % j != 0){
        //printf("break %d",j);
        break;
      }
      if(r % j == 0){
         r = r / j;
         if(r == 0)
           break;
      }
    }
      len = j - i;
      //printf("\nlen = %d\n",len);
      if(maxi < len){
        maxi = len;
        x = i;
      }
  }

  printf("%d\n",maxi);
  for(i = 0;i < maxi;i++){
    printf("%d",x + i);
    if(i != maxi - 1)
        printf("*");
    }
}
