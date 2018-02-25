//第一次提交15,有两个测试点超时,感觉需要自己归纳出一个函数式，简化编程
#include<cstdio>
const int N = 100200;
int main(){
  int i,j = 0;
  int num = 0;
  double a[N];
  scanf("%d",&num);
  for(i = 0;i < num;i++){
    scanf("%lf",&a[i]);
  }
  double res = 0;
  /*
  for(i = 0;i < num;i++){
    for(j = i;j < num;j++){
      res += (num - j) * a[j];
    }
  }
  */
  for(i = 0;i < num;i++){
    res += (num - i )*(i+1)*a[i];
    
  }
  printf("%.2f\n",res);
  return 0;
}
