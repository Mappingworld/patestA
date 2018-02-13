#include<cstdio>
#include<cstring>
struct s{
char na[12];
char id[12];
} p[1000];
int main(){
int nu = 0;
scanf("%d",&nu);
int i = 0;
for( i = 0;i < nu ;i++){
  scanf("%s %s",p[i].na,p[i].id);
}
int strl = 0;
int res[1000];
int j = 0;
int t=0;
int k = 0,f = 0;
for( i = 0;i < nu ;i++){
   strl = strlen(p[i].id);
   for(j = 0;j < strl;j++){
     if(p[i].id[j] == '1'){
        p[i].id[j] = '@';
        f = 1;
     }
     if(p[i].id[j] == '0'){
        p[i].id[j] = '%';
        f = 1;
     }
     if(p[i].id[j] == 'l'){
        p[i].id[j] = 'L';
        f = 1;
     }
     if(p[i].id[j] == 'O'){
        p[i].id[j] = 'o';
        f = 1;
    }
   }
  if(f == 1){
      t++;
      f = 0;
      res[k++] = i;
    }
}
int v[nu] ={0} ;
if(k == 0){
for(i = 0;i < nu;i++){
    if(v[i] != -1){
      for(j = i+1;j < nu;j++){
        if(strcmp(p[i].na,p[j].na) == 0){
              v[j] = -1;
        }
      }
    }
}
j=0;
for(i = 0;i < nu;i++){
    if(v[i] == 0){
        j++;
    }
}
if(j == 1)
  printf("There is %d account and no account is modified",j);
if(j >1)
  printf("There are %d account and no account is modified",j);
return 0;
}
printf("%d\n",k);

for(i = 0;i < k;i++){
  printf("%s %s\n",p[res[i]].na,p[res[i]].id);
}

return 0;
}
