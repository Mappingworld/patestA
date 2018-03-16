#include<cstdio>
#include<vector>
using namespace std;
const int MAXI = 100000;
vector<int> w1,w2,w3;
int m[MAXI][2];

int main(){
 int i = 0;
 int num,fir,k;
 int a,b,c;
 scanf("%d %d %d",&fir,&num,&k);
 for(i = 0;i < num;i++) {
 scanf("%d %d %d",&a,&b,&c);
 m[a][0] = b;
 m[a][1] = c;
 }
 printf("read finished\n");
int r = fir;
 while(r != -1){
 if(m[r][0] < 0){
 w1.push_back(r);
 }
 if(m[r][0] > k){
 w3.push_back(r);
 }
 if(m[r][0] <= k&& m[r][0] >= 0){
 w2.push_back(r);
 }
 r = m[r][1];
 }
 int k1 = w1.size();
 for(i = 0 ;i < k1;i++){
 if(i == 0)
 printf("%05d %d ",w1[i],m[w1[i]][0]);
 else
 printf("%05d\n%05d %d ",w1[i],w1[i],m[w1[i]][0]);
 }
 //printf("%04d\n",m[w1[i]][1]);
int k2 = w2.size();
 for(i = 0 ;i < k2;i++){
 if(i == 0)
 printf("%05d\n%05d %d ",w2[i],w2[i],m[w2[i]][0]);
 else
 printf("%05d\n%05d %d ",w2[i],w2[i],m[w2[i]][0]);
 }
 //printf("%04d\n",m[w2[i]][1]);
 int k3 = w3.size();
 if(k3 == 0){
 printf("-1");
 }else{
 for(i = 0 ;i < k3;i++){
 if(i == 0)
 printf("%05d\n%05d %d ",w3[i],w3[i],m[w3[i]][0]);
 else
 printf("%05d\n%05d %d ",w3[i],w3[i],m[w3[i]][0]);
 }
printf("-1");
 }
}
