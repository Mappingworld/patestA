#include<cstdio>
const int N=54;
int main(){
int Ar1[N]={0};
int Ar2[N]={0};
int Art[N]={0};
int* Arp=Ar1;
int t=0;
int i=0;
int j=0;
for(i=0;i<N;i++){
Ar1[i]=i;
}
scanf("%d",&t);
for(i=0;i<N;i++){
scanf("%d",&Art[i]);
Art[i]--;
}

for(j=0;j<t;j++){
for(i=0;i<N;i++){
 Ar2[Art[i]]=Arp[i];
}
for(int o=0;o<N;o++){
 Arp[o]=Ar2[o];
}

//printf("\n-------------------\n");
/*for(int k=0;k<N;k++){
 printf("%d ",Arp[k]);
}
*/
}

//printf("\n");
for(i=0;i<N;i++){
 j=(Arp[i])/13;
 // printf("%d ",Arp[i]);
 if(j==0)
 printf("S");
 else if(j==1)
 printf("H");
 else if(j==2)
 printf("C");
 else if(j==3)
 printf("D");
 else
 printf("J");
 printf("%d",(Arp[i])%13+1);
 if(i<N-1)
 printf(" ");
}
return 0;
}
