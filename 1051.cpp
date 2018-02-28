#include<cstdio>
#include<stack>
using namespace std;

int main(){
 int ro;
 int cao;
 int tim;
 int s[1000];
 scanf("%d %d %d",&ro,&cao,&tim);
 int i = 0;
 int cun = 0;
 int j ,flg= 0;
 while(tim--){
   for(i = 0;i < cao;i++){
     scanf("%d",&s[i]);
   }
   stack<int> m;
   flg = 0;
   j = 1;
   cun = 0;
   //
   //printf("888\n");
   while(cun < cao && j <= cao){

     m.push(j);
     j++;
     //printf("push %d\n",j - 1);
     if(s[cun] != m.top() ){
       m.push(j);
     //  printf("push %d\n",j);
       j++;
     }
     if(m.size() > ro){
        flg = 2;
        break;
     }
     while( !(m.empty()) &&s[cun] == m.top()  ){
        cun ++;
      //  printf("ww\n");
     // printf("pop %d\n",m.top());
        m.pop();

     }
   }

   if(cun < cao - 1 || flg == 2){
    printf("NO\n");
   }
   else
    printf("YES\n");



 }

}
