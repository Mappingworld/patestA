#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int mu;

const int MAXI = 109;
struct p{
int va;
vector<int> m;
}q[MAXI];
bool qq(int a,int b){
 struct p c = q[a];
 struct p d = q[b];

  return c.va > d.va;
}

int p[MAXI] = {0};
void dfs(int a,int k,int j){
 struct p b = q[a];
  k += b.va;
   p[j] = b.va;
  if(k > mu){
    return ;
  }
  int i = 0;
  if(k == mu){
    if(b.m.size() != 0){
        return ;
    }
    else
     for(i = 0;i < j + 1;i++){
        printf("%d",p[i]);
        if(i != j ){
            printf(" ");
        }
        else
            printf("\n");
     }
  }
  for(vector<int>::iterator it = b.m.begin();it != b.m.end();it++)
     dfs(*it,k,j + 1);
}


int main(){
int num;
int fey;
scanf("%d %d %d",&num,&fey,&mu);
int i ,j = 0;
for(i = 0;i < num;i++){
  scanf("%d",&q[i].va);
}
int a,b,c;
for(i = 0;i < fey;i++){
  scanf("%d %d",&a,&b);
  for(j = 0;j < b;j++){
    scanf("%d",&c);
    q[a].m.push_back(c);
  }
  sort(q[a].m.begin(),q[a].m.end(),qq);//对vector进行排序
}
  dfs(0,0,0);

}
