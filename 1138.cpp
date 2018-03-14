#include<cstdio>
#include<vector>
using namespace std;
vector<int> pre,in;
void seekz(int pres,int pree,int ins,int ine){
  //printf("%d %d %d %d\n",pres,pree,ins,ine);
  int i = 0;
  if(ine == 0){
    printf("%d",in[0]);
    return ;
  }
  if(ine == -1){
    printf("%d",in[1]);
    return ;
  }
  while(pre[pres] != in[i])
    i++;
  seekz(pres + 1,pres + i,ins,i - 1);

}
int main(){
  int num;
  int a;
  scanf("%d",&num);
  int i = 0;
  for(;i < num;i++){
    scanf("%d",&a);
    pre.push_back(a);
  }
  for(i = 0;i < num;i++){
    scanf("%d",&a);
    in.push_back(a);
  }
  seekz(0,num - 1,0,num - 1);


}
