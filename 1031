/*读取字符串的长度的函数strlen*/
#include<cstdio>
#include<cstring>
int main(){
char s[100];
int j=0,i=0;
scanf("%s",s);
int m=strlen(s);
int k=m/3;
int le=m%3;
for(i=0;i<k;i++){
printf("%c",s[i]);
for(j=0;j<k+le-2;j++){
printf(" ");
}
printf("%c\n",s[m-1-i]);
}
for(i=0;i<k+le;i++){
printf("%c",s[k+i]);
}
}
