#include<cstdio>
const int N=100000;
int main(){
int e[N]={0};
int s[N+1]={0};
int num=0;
int t=0;
int q[10000][2];
int i=0;
int sum=0;
int tem=0;
int j=1;
scanf("%d",&num);
for(i=0;i<num;i++){
scanf("%d",&e[i]);
sum+=e[i];
s[j++]=sum;
}
int sum1=sum/2;

scanf("%d",&t);
for(i=0;i<t;i++){
scanf("%d %d",&q[i][0],&q[i][1]);
if(q[i][0]>q[i][1]){
 tem=q[i][0];
 q[i][0]=q[i][1];
 q[i][1]=tem;
}
}

/*for(i=0;i<num;i++){
    printf("%d ",s[i]);
}*/
//printf("\n");
for(i=0;i<t;i++){
/*j=q[i][0];
for(q[i][0]=0;j<q[i][1];j++){
  q[i][0]+=e[j-1];
}*/

q[i][0]=s[q[i][1]-1]-s[q[i][0]-1];
if(q[i][0]>sum1)
  q[i][0]=sum-q[i][0];

}
/*printf("\nsum =%d\n",sum);
for(i=0;i<t;i++){
printf("%d - %d\n",q[i][0],q[i][1]);
}*/
for(i=0;i<t;i++){
printf("%d\n",q[i][0]);
}

return 0;
}
