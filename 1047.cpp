#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
char m[40000][5];
vector<int> vi[2510];
bool cmp(int a,int b){
  return strcmp(m[a],m[b]) < 0;
}
int main(){
  int snum;
  int cnum;
  scanf("%d %d",&snum,&cnum);
  int i ,j = 0;
  int a;
  int b;
  for(i = 0;i < snum;i++){
    scanf("%s %d",m[i],&a);//看别人是怎么存储字符串数组的,是直接使用二维字符数组
    for(j = 0;j < a;j++){
      scanf("%d",&b);
      vi[b].push_back(i);
    }
  }
  for(i = 1;i <= cnum;i++){
    printf("%d %d\n",i,vi[i].size());
    sort(vi[i].begin(),vi[i].end(),cmp);//begin(),end()返回值都是指针
    for(j = 0;j < vi[i].size();j++){
        printf("%s\n",m[vi[i][j]]);
    }

  }


}
