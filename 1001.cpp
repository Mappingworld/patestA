#include<cstdio>
int main(){
int  a=0;
int b=0;
int i=0;
char c[10];
scanf("%d %d",&a,&b);
a=a+b;
if(a<0){
printf("-");
a=-a;
}
if(a==0){
    printf("0");
    return 0;
}
while(a!=0){
  c[i]=a%10+'0';
 // printf(" %d %c\n",i,c[i]);
  i++;
  a=a/10;
}

do{
 printf("%c",c[--i]);
 if(!((i-3)%3)&&(i!=0))
   printf(",");
}while(i>0);
return 0;
}
