#include<cstdio>
const int N=1001;
int main(){
double f[2][N]={0.0};
double s[2*N]={0.0};double m=0.0;
int i,j=0;int a=0;int b=0;
for(i=0;i<2;i++){
  scanf("%d",&a);
  for(j=0;j<a;j++){
  scanf("%d %lf",&b,&m);
  f[i][b]=m;
  }
}
for(i=0;i<N;i++){
  if(f[0][i]!=0.0){
     for(j=0;j<N;j++){
       if(f[1][j]!=0.0){
        s[i+j]+=f[0][i]*f[1][j];
       }
     }
  }
}
i=0;
for(j=0;j<2*N;j++){
  if(s[j]!=0.0){
   i++;
  }
}
printf("%d",i);
if(i!=0)
printf(" ");

for(j=2*N-1;j>=0;j--){
  if(s[j]!=0.0){
   printf("%d %.1lf",j,s[j]);
   i--;
 if(i!=0)
  printf(" ");
  }

}

return 0;
}
