/*#include<cstdio>
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
*/
#include<cstdio>


int main(){
  int a1,a2,a3,b1,b2,b3;
  scanf("%d.%d.%d %d.%d.%d",&a1,&a2,&a3,&b1,&b2,&b3);
  int k1 = 0,k2 = 0;
  if(a3 + b3 > 28){
     k1 = 1;
     a3 = a3 + b3 - 29;
  }else{
     a3 = a3 + b3;
  }
  if(b2 + a2 + k1> 16){
    k2 = 1;
    a2 = b2 + a2 - 17 + k1;
  }else{
    a2 = b2 + a2 + k1;
  }
  printf("%d.%d.%d",a1 + b1 + k2,a2,a3);

}
