#include<cstdio>
#include<cstring>

int c[10]={0,1,20,300};
char d[10] ;

int to_inter(int i,int m,char n[]){
  int j =0;
  int y = 0;
  int p = 1;
  //printf("i = %d\n",i);
  for(j = m - 1;j > i;j--){
    //printf("k =%c",d[j]);
    y += (n[j] - '0') * p;
    p *= 10;
  }
  //printf("y = %d\n",y);
  return y;
}

int main(){
  char d[10] ;
  int i = 0;
  scanf("%s",d);
  int m = strlen(d);
  int res = 0;
  int k = 1000;
  for(i = 4;i < 10;i++){
    c[i] = c[i - 1] * 10 +k;
    k *= 10;
    //printf("%d ",c[i]);
  }
  //printf("\n");
  int re = 0;

  int e = 1;
  for(i = 1;i < m;i++){
    e *= 10;
  }
  //printf("e = %d\n",e);
  for(i = 0;i < m;i++){
    if(d[i] > '1'){
      // printf("%d * %d + %d\n",d[i]-'0',c[m - i - 1],e);
      re += (d[i] - '0')*c[m - i - 1] + e;

    }
    if(d[i] == '1'){
    //  printf("%d * %d + %d\n",d[i]-'0',c[m - i - 1],to_inter(i,m,d) + 1);
      re += (d[i] - '0')*c[m - i - 1] + to_inter(i,m,d) + 1;

    }
    e = e /10;

  }
  printf("%d",re);
}
