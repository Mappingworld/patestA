//+2.111111111111E+01 +21111111111.11
#include<cstdio>
#include<cstring>
int main(){
char s[10020];
scanf("%s",s);
int i = 0;
int str = strlen(s);
for(i = 0;i < str;i++){
 if(s[i] == 'E')
   break;
}
int len = i;
int t = 0, b = 1;
for(i = str-1;i >= len+2;i--){
  t+= (s[i] - '0') * b;
  b*= 10;
}
if(t==0){
    for(i = 0;i < len;i++){
        printf("%c",s[i]);
    }
    return 0;
}
int j=0;
printf("t=%d \n",t);
if(s[0]!='+')
  printf("%c",s[0]);
if(s[len+1] == '+'){
  printf("%c",s[1]);
  for(i = t;i > 0;i--){
    if(j+3 < len){
       if(s[j+3]!='.')
       printf("%c",s[j+3]);
       j++;
    }
    else
       printf("0");
  }
  if(j+3 < len){
    printf(".");
    for(;j+2 < len-1;j++){
      if(s[j+3]!='.')
        printf("%c",s[j+3]);
    }
  }
}

if(s[len+1] == '-'){
  printf("0.");
  for(i = t-1;i > 0;i--){
       printf("0");
  }
  printf("%c",s[1]);
  for(i = 3;i < len ;i++){
      printf("%c",s[i]);
  }
}

return 0;
}
