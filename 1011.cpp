#include<cstdio>
int main(){
double a[3][3]={0.0};
double re=1.0;
int i=0;int j=0;
double max=0;char imax='W';
for(i=0;i<3;i++){
    for(int k=0;k<3;k++){
      scanf("%lf",&a[i][k]);
    }
}
j=1;
for(i=0;i<3;i++){
  max=a[i][0];
  imax='W';
  if(max<a[i][1]){
     max=a[i][1];
     imax='T';
  }
  if(max<a[i][2]){
     max=a[i][2];
     imax='L';
  }
  printf("%c ",imax);
  re*=max;
}
printf("%.2lf",(re*0.65-1.0)*2.0);
}
