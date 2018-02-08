#include<cstdio>
const int N=1001;
int main(){
 double num[N]={0.0};
 int i,j=0;
 int s1=0;
 int s=0;
 double q=0.0;
 for(i=0;i<2;i++){
 scanf("%d",&s1);
 for(j=0;j<s1;j++){
 scanf("%d %lf",&s,&q);
 num[s]+=q;
 }
 }
 j=0;
 for(i=N-1;i>=0;i--){
 if(num[i]!=0.0)
 j++;
 }
 printf("%d",j);
 if(j!=0)
 printf(" ");
 for(i=N-1;i>=0;i--){
 if(num[i]!=0.0){
 printf("%d %.1lf",i,num[i]);
 j--;
 if(j!=0)
 printf(" ");
 }
 }
}
