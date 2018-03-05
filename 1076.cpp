#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
const int MAXI = 1000;//1000
vector<int> s[MAXI];

bool sig[MAXI];
int turn;
int kk = 0;
void sc(int b,int j){
 //printf("b = %d j = %d",b,j);
 if(sig[b] == false)
 kk ++;
 //printf(" %d\n",kk);
 sig[b] = true;
 if(j >= turn){
 return ;
 }
 int x = s[b].size();
 int i = 0;
 for(i = 0;i < x;i++){
 sc(s[b][i],j + 1);
 }
}
int main(){
int i = 0;
int num;
int b;
int a;
int j = 0;
int c = 0;
scanf("%d %d",&num,&turn);
for(i = 0;i < num;i++){
 scanf("%d",&b);
 for(j = 0;j < b;j++){
 scanf("%d",&c);
 s.push_back(i + 1);
 }
}
scanf("%d",&a);

for(i = 0;i < a;i++){
 scanf("%d",&b);
 kk = 0;
 memset(sig,false,sizeof(sig));
 //printf("WILL in>>>>>>>>>>>>>>\n");
 sc(b,0);
 printf("%d\n",kk - 1);
}

}
