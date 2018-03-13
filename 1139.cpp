#include<cstdio>
#include<algorithm>
#include<vector>
const int MAXI = 100000;
using namespace std;
vector<int> link[MAXI];
vector<int> s1;
vector<int> s2;
int sex[MAXI] = {0};
int aa,bb;
int aas = 0,bbs = 0;
vector<int> yyy ;
void o(){
   //printf("%d1003\n\n",sex[1003]);
  int i = 0;
  int s = link[aa].size();
  s1.clear();
  s2.clear();
  for(i = 0;i < s;i++){
    //printf("添加可能人%d%d\n",sex[link[aa][i]] ,link[aa][i]);
    if(sex[link[aa][i]] == aas&&link[aa][i] != bb){
        //printf("添加没人%d\n",link[aa][i]);
        s1.push_back(link[aa][i]);
    }
  }
 // printf("\n");
  s = link[bb].size();
  for(i = 0;i < s;i++){
    //printf("添加可能人%d%d\n",sex[link[bb][i]] ,link[bb][i]);
    if(sex[link[bb][i]] == bbs&&link[bb][i] != aa){
      //  printf("添加媒人%d\n",link[bb][i]);
        s2.push_back(link[bb][i]);
    }
  }
  //printf("双方媒人准备完毕\n");
  for(i = 0;i < s1.size();i++){
    //printf("%d  ",s1[i]);
  }
  //printf("\n");
  for(i = 0;i < s2.size();i++){
    //printf("%d  ",s2[i]);
  }

}
bool qq(int a,int b){
  return a < b;
}
int find1(int a,int b){
  int i = 0;
  for(i = 0;i < link[a].size();i++){
     if(link[a][i] == b){
        return 1;
     }
  }
  return 0;
}
void oo(){
  yyy.clear();
  int i = 0;
  int j = 0;
  int k = s1.size();
  int kk = s2.size();
  //printf("进行匹配\n");
  for(i = 0;i < k;i++){
    for(j = 0;j < kk;j++){
     if(find1(s1[i],s2[j]) == 1){
        yyy.push_back(s1[i]);
        yyy.push_back(s2[j]);
       // printf("%d %d\n",s1[i],s2[j]);
     }
    }
  }
}


int main(){
  int i = 0;
  int j = 0;
  int a,b;
  int pnum,lnum;
  scanf("%d %d",&pnum,&lnum);
  for(i = 0;i < lnum;i++){
    scanf("%d %d",&a,&b);
    if(a > 0){
        sex[a] = 1;
    }else{
        a = -a;
        sex[a] = 0;
    }
    if(b > 0){
        sex[b] = 1;
    }else{
        b = -b;
        sex[b] = 0;
    }
    //printf("%d%d %d%d\n",sex[a],a,sex[b],b);
    // printf("000k");
    link[a].push_back(b);
    //printf("llll");
    link[b].push_back(a);
   // printf("")
    //printf("999");
  }
  //printf("关系读取完毕\n");
  //printf("%d1003\n\n",sex[1003]);
  int qnum = 0;
  scanf("%d",&qnum);
   //printf("%d1003\n\n",sex[1003]);
  for(i = 0;i < qnum;i++){
    scanf("%d %d",&a,&b);
     //printf("%d1003\n\n",sex[1003]);
    if(a > 0){
        aa = a;
        aas = 1;
    }else{
       aa = -a;
       aas = 0;
    }
    if(b > 0){
        bb = b;
        bbs = 1;
    }else{
        bb = -b;
        bbs = 0;
    }
    //printf("问题读取完毕\n");
    //printf("%d1003\n\n",sex[1003]);
    o();
    sort(s1.begin(),s1.end(),qq);
    sort(s2.begin(),s2.end(),qq);
    //printf("排序完毕\n");
    oo();
    int u = yyy.size();
    printf("%d\n",u/2);
    for(j = 0;j < u/2;j++){
        printf("%04d %04d\n",yyy[j * 2],yyy[j * 2 + 1]);
    }
  }
}
