#include<cstdio>
int main(){
int i=0,numb=0;int list[100]={0};int time=0;
scanf("%d",&numb);
for(i=0;i<numb;i++)
 scanf("%d",&list[i]);

if(numb>0)
 time=list[0]*6+5;

for(i=1;i<numb;i++){
 if(list[i]>list[i-1]){
 time+=(list[i]-list[i-1])*6+5;

 }
 if(list[i]<=list[i-1]){
 time+=(list[i-1]-list[i])*4+5;

 }
}
printf("%d",time);
return 0;
}
