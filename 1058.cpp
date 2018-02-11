#include<cstdio>
int main(){

int n[6]={0};
scanf("%d.%d.%d %d.%d.%d",&n[0],&n[1],&n[2],&n[3],&n[4],&n[5]);
int i=0;
for(i=0;i<3;i++){
 n[i]+=n[i+3];
}
int j=0;
if(n[2]>29){
 n[2]=n[2]-29;
 n[1]+=1;
}
if(n[1]>17){
  n[1]=n[1]-17;
  n[0]+=1;
}
printf("%d.%d.%d",n[0],n[1],n[2]);
}
