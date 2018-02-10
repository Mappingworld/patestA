#include<cstdio>
struct p{
char s[15];
int hh1,mm1,ss1;
} n1,n2,temp;

bool comB(p p1,p p2){//p1>p2,true
  if(p1.hh1>p2.hh1) return true;
   if(p1.hh1==p2.hh1&&p1.mm1>p2.mm1) return true;
    if(p1.hh1==p2.hh1&&p1.mm1==p2.mm1&&p1.ss1>p1.ss1) return true;
 return false;
}

int main(){
int num=0;
n1.hh1=25;
int i=0;
scanf("%d",&num);
for(i=0;i<num;i++){
  scanf("%s",temp.s);
  scanf("%d:%d:%d",&temp.hh1,&temp.mm1,&temp.ss1);

  if(!comB(temp,n1)) n1=temp;
  scanf("%d:%d:%d",&temp.hh1,&temp.mm1,&temp.ss1);
  if(comB(temp,n2)) n2=temp;

}
printf("%s %s",n1.s,n2.s);

}
