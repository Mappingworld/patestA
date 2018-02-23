#include<cstdio>
#include<algorithm>
const int N = 100000;
int main(){
int np;
int mp;
int i , j;
int n[N];
int m[N];
scanf("%d",&np);
for(i = 0;i < np;i++){
  scanf("%d",&n[i]);
}
scanf("%d",&mp);
for(i = 0;i < mp;i++){
  scanf("%d",&m[i]);
}
std::sort(n,n+np);
std::sort(m,m+mp);
int sum = 0;
j = 0;
for(i = 0;n[i] < 0;i++){
   if(m[j] >= 0)
     break;
   sum += m[j] * n[i];
   j++;
}
j = mp -  1;
for(i = np - 1; n[i] > 0;i--){
   if(m[j] <= 0)
    break;
   sum += m[j] * n[i];
   j --;
}
printf("%d",sum);

}
