//题目理解出现的不重复的第一个数字输出
//嵌套式 的系数数组结构处理
#include<cstdio>
int main(){
  int num = 0;
  scanf("%d",&num);
  int i = 0;
  int a[10000]={0};
  int s[10000]={0};
  for(i = 0;i < num;i++){
    scanf("%d",&a[i]);
    s[a[i]] ++;
  }
  for(i = 0;i < num;i++){
    if(s[a[i]] == 1){
      printf("%d",a[i]);
      break;
    }
  }
  if(i == num)
    printf("None");


}
