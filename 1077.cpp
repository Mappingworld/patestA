//在用了scanf()后用gets时,需要用getchar（）
#include<cstdio>
#include<cstring>
int main(){
int nu = 0;
char s[100][300];
char strl[100];
char res[300];
scanf("%d",&nu);
getchar();
int i = 0;
int mi=256;
int si=0;
for(i = 0;i < nu;i++){
   gets(s[i]);
   strl[i] = strlen(s[i]);
   if(mi > strl[i]){
    mi = strl[i];
    si = i;
  }
}
for(i =  0;i < nu;i++){
    //printf("\n%s",s[i]);

}
int k = 0;int j = 0;
for(j = strl[si]-1;j >= 0; j--){
   k++;
  // printf("sss%csss\n",s[si][j]);
   for(i = 0;i < nu;i++){

      if(s[si][j] != s[i][strl[i]-k])
        break;
   }
   if( i < nu)
     break;
}
//printf("￥￥￥%d\n",j);
j++;
if(j == strl[si])
    printf("nai");
if(j < strl[si]){
  for(;j < strl[si];j++){
    printf("%c",s[si][j]);
  }
}

}
