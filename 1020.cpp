#include<cstdio>
#include<vector>
using namespace std;
vector<int> post,in,u(10000,-1);
void turn(int ps,int pe,int is,int ie,int d){
  //printf("%d %d %d %d %d\n",ps,pe,is,ie,d);
  if(is == ie + 1 || ps == pe + 1){
    return ;
  }
  u[d] = post[pe];
  int i = 0;
  for(i = is;i <= ie;i++){
    if(in[i] == u[d]){
        break;
    }
  }
  int leng1 = i - is;
  turn(ps,ps + leng1 - 1,is,i - 1,d * 2);
  turn(ps + leng1,pe - 1,i + 1,ie,d * 2 + 1);
}

int main(){
  int i = 0;
  int num = 0;
  scanf("%d",&num);
  int a;
  for(i = 0;i < num;i++){
    scanf("%d",&a);
    post.push_back(a);
  }
  for(i = 0;i < num;i++){
    scanf("%d",&a);
    in.push_back(a);
  }
  int j = 0;
  turn(0,num - 1,0,num - 1,1);
  for(i = 0;i < 10000;i++){
    if(u[i] != -1){
        printf("%d",u[i]);
        j++;
        if(j < num){
            printf("*");
        }
    }
  }

}
