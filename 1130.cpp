#include<cstdio>
#include<vector>
#include<string>
#include<iostream>
#include<cstring>
const int MAXI = 30;
using namespace std;
string ans;
struct p{
 string a;
 int left;
 int right;
};
vector<struct p> m;

//对于一个已知结构的树进行中序遍历
//直接用dfs进行中序遍历

//前序
void qiand(int t){
 //printf("t = %d",t);
 if(t != -1){
    cout << m[t].a;
 }
 if(m[t].left != -1){
    qiand(m[t].left);
 }
 if(m[t].right != -1){
    qiand(m[t].right);
 }

}
//h后序
void houd(int t){
  if(m[t].left != -1){
    houd(m[t].left);
  }
 if(m[t].right != -1){
    houd(m[t].right);
 }
 cout << m[t].a;
}
//中序
int mm;
void zhongd(int t){
 if( t != mm&& (m[t].left != -1||m[t].right != -1))
   cout << "(";
 if(m[t].left != -1){

    zhongd(m[t].left);
 }
 cout << m[t].a;
 if(m[t].right != -1){

    zhongd(m[t].right);
 }
if( t != mm&& (m[t].left != -1||m[t].right != -1))
   cout << ")";
}
//进行序的遍历时，要注意的就是你先要处理的是那一部分，你要明白大体的思路按思路写
int sign[MAXI];
int main(){
  memset(sign,-1,sizeof(sign));
  int m1 = 0;
  scanf("%d",&m1);
  int i = 0;
  struct p pp;
  string s;
  int b,c;
  m.push_back(pp);
  for(i = 0;i < m1;i++){
    cin >>s >>b>>c;
    pp.a = s;
    if(b != -1 ){
        sign[b] = 1;
    }
    if(c != -1){
        sign[c] = 1;
    }
    pp.left = b;
    pp.right = c;
    m.push_back(pp);
  }//这种结构形式更加有方便一些
  //printf("read finished\n");
  //接下来对建好的树进行遍历，首先确定头节点
  int to = 0;
  for(i = 1;i <= m1;i++){
    if(sign[i] != 1){
        to = i;
        break;
    }
  }
  mm = to;
 // printf("to%d\n",to);
  //qiand(to );
   //printf("\n");
  //houd(to);
   //printf("\n");
  zhongd(to);
}
