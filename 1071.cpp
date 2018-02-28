//in a   out a 1   in b!a ba aa  out aa
#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<map>
using namespace std;
const int N = 200;//1048576
/*
*这里有一处花费了很久。就是在将字符char a存储到一个字符串string b类型中时，我发现将string类型看作字符数组进行存入
*如：b[j++] = a;
*是可以存入的，可以通printf("%c"，b[j]),将他们独处，
*但是似乎并不被认可作为string的一部分，以至于对b进行输出时，cout<< b,b为空；
*后来查看资料找到了处理办法，只能将b作为string读取数据，数据才会被认可为string的一部分，b += a;
*/

map<string,int> ma;
int main(){
  string m;

  int len ;
  int w = 9;
  int j , i = 0;
   int q = 'a' - 'A';
   //这里没有告知长度因此只能将一整行读取
   getline(cin,m);//getline只能读取string
   int lend = m.length();
   int o;
   while(i < lend){
     string u;
     for( ;i < lend&&m[i] != ' ';i++){
            //cout << i <<" ";
       if((m[i] >= 'A'&&m[i] <='Z')||(m[i] >= 'a'&&m[i] <= 'z')||(m[i] >= '0'&&m[i] <= '9') ){
          if(m[i] >= 'A'&&m[i] <='Z')
             m[i] += q;
             u += m[i];
             //printf("%c",u[j -1]);
           }
      else
        break;


    }
    //u[j] = '\0';
    //for(o = 0;o <= j;o++)
    //printf("%c",u[o]);
      // u = "heheheheh";
    //u[j] = '\0';
   //        cout<<u<<"\n";
        if(u.length() > 0){
           if(ma.find(u) != ma.end()){
              ma[u]++;
           }
           else
             ma[u] = 1;
        }
    i++;
  }
    int max = 0;
    string x;
    for(map <string,int>::iterator it = ma.begin();it != ma.end();it++){
       if(max < it -> second){
         max = it -> second;
         x = it -> first;
       }
    }
    cout<<x;
    printf(" %d",max);
}
