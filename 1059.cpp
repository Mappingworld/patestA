#include<cstdio>
//假设只进行1000000以内的素数表的建立
const int MU = 500000;
const int MAXI = 500000;
bool flg[MAXI] = {0};
int p[2][MAXI];
int r = 0;
void prime_table(){
 int i = 0;
 int j = 0;
 for(i = 2;i < MU;i++){
 if(flg[i] == false){
 p[0][r++] = i;
 // printf("flg %d",i);
 for(j = i + i;j < MU;j += i){
 // printf("OOK");
 flg[j] = true;
 }
 }
 }
}
int main(){
int m = 0;
scanf("%d",&m);
prime_table();//建立了1000000以内的素数表
//printf("table is OK\n");
int i = 0;
if(m == 1){
 printf("1=1");
 return 0;
}
int k = m;
//printf("&&&&&&&&");
//printf("%d",r);
for(i = 0;i < r;i++){
 // printf("&&&&&&&&1\n");
 if(k == 1){
 // printf("&&&&&&&&2\n");
 break;
 }else{
 if(k % p[0][i] == 0){
 // printf("pp%d",p[0][i]);
 p[1][i] ++;
 k = k / p[0][i];
 i --;

 }
 }
}
int u = 0;
for(i = 0;i < r;i++){
 if(p[1][i] != 0){
 u++;
 }
}
if(k != 1){
 u++;
}
printf("%d=",m);
for(i = 0;i < r;i++){
 if(p[1][i] == 1){
 u --;
 printf("%d",p[0][i]);
 if(u != 0){
 printf("*");
 }
 }
 if(p[1][i] > 1){
 u --;
 printf("%d^%d",p[0][i],p[1][i]);
 if(u != 0){
 printf("*");
 }
 }
}
if(k != 1){
 printf("%d",k);
}
}
