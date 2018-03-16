#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string ss;
string bb;
string kk;
void rever(string ss){
  int num = ss.size();
  int i = 0;
  for(i = 0;i < num;i++){
     bb[i] = ss[num - i -1];
     printf("%c",bb[i]);
  }
  bb[i] = '\0';
  printf("rever number :");
  cout << bb;
}
void addd(string a,string b){
  //printf("进行相加操作:");
  //cout << a << " + " << b;
  //printf("\n");
  int num1 = a.size();
  int i= 0;
  int jin = 0;
  /*for(i = num1 -1;i >= 0;i--){
    if(a[i] - '0' + b[i] - '0' + jin>= 10){
       jin = 1;
       kk[i + 1] = a[i] - '0' + b[i] - '0' + jin - 10 + '0';
    }
    else{
       kk[i + 1] = a[i] - '0' + b[i] - '0' + jin + '0';
       jin = 0;
    }
  }
  if(jin > 0){
     kk[0] = jin + '0';
  }*/
  for(i = 0;i < num1 ;i++){
        if(a[i] - '0' + b[i] - '0' + jin >= 10){
            kk += a[i] + b[i] - '0' + jin - 10;
             jin = 1;
        }
        if(a[i] - '0' + b[i] - '0' + jin < 10){
            kk += a[i] + b[i] - '0' + jin;
             jin = 0;
        }
  }
  if(jin > 0){
    kk += 1 + '0';
  }
  reverse(kk.begin(),kk.end());
   //printf("相加结束结果为");
   ///cout << kk;//是否需要再末尾添加\0
   //printf("\n");
}

int main(){
 cin >> ss;
 int i = 0;
 bb = ss;
 reverse(bb.begin(),bb.end());
 int time = 0;
 while(ss.compare(bb)){
   if(++time > 10)
     break;
   addd(ss,bb);
   cout << ss << " + " << bb << " = " << kk << "\n";
   ss = kk;
   kk.clear();
   bb = ss;
   reverse(bb.begin(),bb.end());
 }
 if(ss.compare(bb) == 0){
   cout << ss << " is a palindromic number.";
 }
 else{
   printf("Not found in 10 iterations.");
 }

}
