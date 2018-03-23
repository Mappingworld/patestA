#include<set>
#include<cstdio>
#include<cstring>
using namespace std;
set<int> m;
int main(){

int num;
scanf("%d",&num);
int i ,j= 0;
char  n[5];
int k = 0;
int  y = 0;
for(i = 0;i < num;i++){
  scanf("%s",&n);
  k = strlen(n);
  y = 0;
  for(j = 0;j < k;j++){
   y += n[j] - '0';
  }
   m.insert(y);
}
y = m.size();
printf("%d\n",y);
j = 0;
for(set <int> ::iterator it = m.begin();it != m.end();it++){
  printf("%d",*it);
  if(++j < y){
    printf(" ");
  }
}
}
