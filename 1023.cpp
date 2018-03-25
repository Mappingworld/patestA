#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
string str;
string ans;
int main(){
 cin >> str;
 int num = str.length();
 //reverse的用法
 reverse(str.begin(),str.end());
 int i= 0;
 int yuan[10] = {0};
 int jie[10] = {0};
 int k = 0;
 int sign = 0;
 int y = 0;
 for(i = 0;i < num;i++){
    y = str[i] - '0';
    yuan[y] ++;
    k  = y * 2 + sign;
    sign  = 0;
    if(k  >= 10){
        jie[k - 10] ++;
        ans += ('0' + k - 10);
        sign = 1;
    }else{
      jie[k] ++;
      ans += ('0' + k);
    }
 }
 if(sign == 1){
    ans += '1';
 }
 reverse(ans.begin(),ans.end());

 for(i = 0 ;i < 10;i++){
    if(jie[i] != yuan[i]){
        printf("No\n");
          cout << ans;
        return 0;
    }
 }
 printf("Yes\n");
  cout << ans;
 return 0;
}
