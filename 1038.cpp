//c++字符串学习：读入和输出整个字符串，只能用cin和cout
#include<cstdio>
#include<algorithm>
#include<string>
#include<iostream>
bool qq(std::string a,std::string b){
  return a + b < b + a;
}
const int N = 10000;//10000
std::string m[N];

int main(){
  int num ;
  scanf("%d",&num);
  int i ,j= 0;
  for(i = 0;i < num;i++){
    std::cin>>m[i];
  }
  std::sort(m,m+num,qq);
  int flg = 0;
  for(j = 0;j < num;j++){
    for(i = 0;i < m[j].length();i++){
      if(m[j][i] != '0'){
        flg = 1;
        break;
      }
    }
    if(flg == 1)
        break;
  }
  if(j == num )
    printf("0");
  for(;i < m[j].length();i++){
    printf("%c",m[j][i]);
  }
  for(i = j+1;i < num;i++){
     std::cout<< m[i];
  }
}
