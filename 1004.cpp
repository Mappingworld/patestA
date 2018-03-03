#include<cstdio>
#include<vector>
using namespace std;
const int MAXI = 1000;
vector <int> m[MAXI];
int book[MAXI] = {0};
int num;
int t = 0;
void treeye(int a,int sb){
    //printf("%d %d\n",a,sb);
    int b = sb;
    if(m[a].size() == 0){
        book[b] ++;
        if(b > t){
            t = b;
        }
        return;
    }
    for(vector<int>::iterator it = m[a].begin();it != m[a].end();it++){
        treeye(*it,b+1);
    }
 }
int main(){
  int i = 0;
  int y = 0;
  scanf("%d %d",&num,&y) ;
  int a = 0;
  int c = 0;
  int j = 0,e = 0;
  for(i = 0;i < y;i++){
    scanf("%d",&a);
    scanf("%d",&e);
    for(j = 0;j < e;j++){
        scanf("%d",&c);
        m[a].push_back(c);
    }
  }
   treeye(1,1);
  for(i = 1;i < t ;i++){
    printf("%d ",book[i]);
  }
  printf("%d",book[i]);
}
