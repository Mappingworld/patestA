//set的使用，对于查看一个set集中是否具有某一元素，如果自己遍历查找，时间过长，会出现运行超时，应该使用set.find(value)这个函数，减少程序的消耗
#include<cstdio>
#include<set>
using namespace std;
set<int>s[50];
int main(){
  int i = 0;
  int num = 0;
  int a = 0;
  int j = 0;
  int b = 0;
  scanf("%d",&num);
  for(i = 0;i < num;i++){
    scanf("%d",&a);
    for(j = 0;j < a;j++){
     scanf("%d",&b);
     s[i].insert(b);//记住方法名
    }
  }
  scanf("%d",&a);
  int c = 0;
  int k = 0;
  set<int>::iterator it;
  set<int>::iterator itm;//set中只能使用迭代器进行取值
//  float w[2000];
  for(i = 0;i < a;i++){
    scanf("%d %d",&b,&c);
    it = s[b - 1].begin();

    for(;it != s[b - 1].end();it++){
     /* for(itm = s[c - 1].begin();itm != s[c - 1].end();itm++){
        if(*it == *itm){
           //  printf("%d %d\n",*it,*itm);
             k ++;
        }

      }
      */

      if(s[c - 1].find(*it) != s[c - 1].end())//find的函数使用
        k++;
    }

    printf("%.1f%%\n",((float)k/(float)(s[b - 1].size() + s[c - 1].size() - k))*100);
    k = 0;
  }

}
