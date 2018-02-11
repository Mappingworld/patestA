/*10^9<2^13
考虑到N为10^9而b为2进制，因此开辟的空间至少为2^x>10^9,x=28.5
*/
#include<cstdio>
int main(){
int m=0,d=0;
int w[30]={0};
scanf("%d %d",&m,&d);
int i=0;
if(m==0){
    printf("Yes\n0");
    return 0;
}
while(m!=0){
w[i++]=m%d;
m=m/d;
}
int k=i;
for(i=0;i<k/2;i++){
if(w[i]!=w[k-1-i])
break;
}
if(i>=k/2)
printf("Yes\n");
else
printf("No\n");
printf("%d",w[k-1]);
for(i=k-2;i>=0;i--){
printf(" %d",w[i]);
}


}
