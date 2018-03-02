//中序遍历特别记忆
//char  + scanf时注意getchar
//memset函数的头文件string.h
//在使用memset是按照字节赋值因此，memset(mi,-1,600);只是将600个字节也就是150int型进行赋值-1
#include<cstdio>
#include<cstring>
struct p{
  int data;
  int R;
  int L;
} s[10],q;
//vector<int> kk;
int num;
int mi[600] ;
int uu= 0;
int k[10];
void inord(int m){//特别记忆

   struct p t = s[m];
  if(t.L != -1)
    inord(t.L);
   printf("%d",t.data);
   uu ++;
    if(uu < num ){
    printf(" ");
  }
  if(t.R != -1)
     inord(t.R);

  return ;
}
int kj = 0;
void ceng(int m,int er){
   if(m == -1)
     return ;
   mi[er] = m;
   //printf("%d m\n");
   struct p t = s[m];
   ceng(t.L,er * 2);
   ceng(t.R,er * 2 + 1);
}
int main(){

 int i = 0;
 scanf("%d",&num);
 char a;
 char b;
 getchar();//之前怎么没有遇到过这种错误的
 for(i = 0;i < num;i++){
   scanf("%c %c",&a,&b);
   getchar();
  // printf("%d %d\n",a,b);
   if(a == '-'){
     s[i].R = -1;
   }else{
      s[i].R = a - '0';
     // printf("%d\n",s[i].R);
   }
   if(b == '-'){
     s[i].L = -1;
   }else{
      s[i].L = b - '0';
       //printf("%d\n",b - '0');
    }
   s[i].data = i;
 }

 int t = 0;
 for(i = 0;i < num;i++){
   if(s[i].L != -1){
     k[s[i].L]++;
   }
   if(s[i].R != -1){
      k[s[i].R]++;
   }
 }
 for(i = 0;i < num;i++){
   if(k[i] == 0){
     t = i;
   }
 }
 //printf("\n%d\n",t);
 memset(mi,-1,sizeof(mi));//在使用memset是按照字节赋值因此，memset(mi,-1,600);只是将600个字节也就是150int型进行赋值-1
 ceng(t,1);
 int f = 0;
 for(i = 0;i < 600;i++){
    if(mi[i] != -1){
        printf("%d",mi[i]);
        f++;
        if(f < num){
            printf(" ");
        }
    }
 }
 printf("\n");
 inord(t);
}
