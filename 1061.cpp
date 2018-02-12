//将两个字符串连接起来的函数
#include<cstdio>
#include<cstring>

int main(){
char s[4][150];
char an[2];
int i=0;
for(i=0;i<4;i++){
scanf("%s",s[i]);
}
int j=0;
int str[4]={0};
for(i=0;i<4;i++){
str[i]=strlen(s[i]);
}
int f=0,t=0;
for(i=0;i<str[0];i++){
if(s[0][i]>=65&&s[0][i]<=71&&f==0){
   if(i<str[1]){
     if(s[0][i]==s[1][i]){
       an[0]=s[0][i];
       f=1;
    //   printf("%d %d\n",i,j);
       i++;
       t=i;
       break;
     }
   }
  }
if((s[0][i]>=65&&s[0][i]<=78&&f==1)||(s[0][i]>='0'&&s[0][i]<='9'&&f==1)){
  // printf("f==1  %c\n",s[0][i]);
   if(i<str[1]){
    //printf("s0 %c s1 %c\n",s[0][i],s[1][j]);
     if(s[0][i]==s[1][i]){
     // printf("%d %d\n",i,j);
      an[1]=s[0][i];
      f=2;
      break;
     }
   }
}
if(f==2)
 break;
}
//printf("%c %c",an[0],an[1]);
/*f=0;int duan=0;
for(i=2;i<4;i++){
for(j=0;j<str[i];){
  while(s[i][j]!='s'&&j<str[i]){
     j++;
    f=1;
  }
  duan+=f;
  while(s[i][j]=='s'&&j<str[i]){
    j++;
    f=0;
  }
}
}
*/

char m[7][10]={"MON","TUE","WED","THU","FRI","SAT","SUN"};

printf("%s ",m[an[0]-65]);
if(an[1]>='A')
printf("%02d:",an[1]-55);
else
    printf("%02d:",an[1]-48);
for(i=0;i<str[2]&&i<str[3];i++){
    if(('a'<s[2][i]&&'z'>s[2][i])||('A'<s[2][i]&&s[2][i]<'Z')){
        if(s[2][i]==s[3][i])
        printf("%02d",i);

    }
}

}
