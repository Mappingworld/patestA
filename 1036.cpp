#include<cstdio>
struct p{
char s[11];
char sex;
char id[11];
int sc;
}n1,n2,tem;

int main(){
  int num=0;
  int i=0;
  n1.sc=101;
  n2.sc=-1;
  scanf("%d",&num);
  for(i=0;i<num;i++){
   scanf("%s %c %s %d",tem.s,&tem.sex,tem.id,&tem.sc);
   if(tem.sex=='M'&&tem.sc<n1.sc){
      n1=tem;
   }
   if(tem.sex=='F'&&tem.sc>n2.sc){
     n2=tem;
   }

  }
   if(n2.sc!=-1)
     printf("%s %s\n",n2.s,n2.id);
    else
      printf("Absent\n");
    if(n1.sc!=101)
     printf("%s %s\n",n1.s,n1.id);
    else
      printf("Absent\n");
    if(n2.sc!=-1&&n1.sc!=101)
     printf("%d",n2.sc-n1.sc);
     else
      printf("NA");

}
