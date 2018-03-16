#include<cstdio>
#include<vector>

using namespace std;
const int MAXI = 100000;
int m[MAXI][2];
vector <int> s;
int main(){
 int fir ;
 int num,k;
 int a,b,c;
 int i;
 scanf("%d %d %d",&fir,&num,&k);
 for(i = 0;i < num;i++){
   scanf("%d %d %d",&a,&b,&c);
   m[a][0] = b;
   m[a][1] = c;
 }
int r = fir;
 while(r != -1){
   s.push_back(r);
   r = m[r][1];
 }
 int len = s.size();
 a = len / k;
 int j ;
 int flg = 0;
 for(i = 0;i < a;i++){
   for(j = k * (i + 1) -  1;j >= k * i;j--){
      if(flg == 0){
        printf("%05d %d ",s[j],m[s[j]][0]);
        flg = 1;
      }
      else
        printf("%05d\n%05d %d ",s[j],s[j],m[s[j]][0]);
   }
 }
 for(i = (a) * k;i < len;i++){
     printf("%05d\n%05d %d ",s[i],s[i],m[s[i]][0]);
 }
 printf("-1");
}
