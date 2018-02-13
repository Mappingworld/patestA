#include<cstdio>
#include<cstring>
int main(){
char s[120];
int d[8];
scanf("%s",s);
int str = strlen(s);
int i = 0;
int sum = 0;
for(i=0;i<str;i++){
  sum += s[i] - '0';
}
//printf("sum = %d",sum);
char n[10][8] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
i=0;
if(sum == 0){
    printf("zero");
    return 0;

}
while(sum != 0){
  d[i++] = sum % 10;
  sum = sum /10;
}

while(i > 0){
  printf("%s",n[d[--i]]);
  if(i != 0)
    printf(" ");
}

}
