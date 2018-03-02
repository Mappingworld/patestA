//题目如何得到结果的完全看不懂，查阅参考资料。才明白push是先序遍历，pop是中序遍历
//对于struct 指针，需要调用里面的元素。可以同->调用
//struct p *a = new struct p;对于建立struct指针的处理
#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;
struct p{
  struct p * R;
  struct p * L;
  int data;
};

const int N = 50;
stack<int> stac;

int pos[N], inord[N],pro[N];
struct p * creatree(int ps,int pe,int is,int ie){
   //printf("%d %d %d %d\n",ps,pe,is,ie);
   if(ps == pe + 1|| is == ie + 1){
     return NULL;
   }

   int i = 0;
   struct p *a = new struct p;
   a->data = pro[ps];

   for(i = is;i <= ie;i++){
     if(inord[i] == a->data)
       break;
   }
    int leng1 = i - is;
    int leng2 = ie - i;
    a->L = creatree(ps + 1,ps + leng1,is,i - 1);
    a->R = creatree(ps + leng1 + 1,pe,i + 1,ie);
     //printf("%d\n",a.data);
    return a;

}
int u = 0;
int num = 0;
void postn(struct p *a){
  //printf("OOOOOOOOOOk\n");
  if(a == NULL){
   return ;
  }
  postn(a->L);
  postn(a->R);
  printf("%d",a->data);
  if(u < num - 1){
    printf(" ");
  }
  u ++;
}
int main(){
  int i = 0;

  char s[5];
  int a;
  int k1 = 0, k2 = 0;
  scanf("%d",&num);
  for(i = 0;i < 2 * num;i++){
    scanf("%s",s);
    //printf("OOOOOOOOOk1\n");
    if(strcmp(s,"Push") == 0){
      scanf("%d",&a);
     // printf("OOOOOOOOOOOOOOOk2\n");
      pro[k1++] = a;
       //printf("OOOOOOOOOOOOOOOk3\n");
      stac.push(a);
       //printf("OOOOOOOOOOOOOOOk4\n");
    }
    else{
      inord[k2++] = stac.top();
      stac.pop();
    }
  }
  struct p *w = creatree(0,num - 1,0,num -1);
 // printf("OOOOK\n");
  //printf("%d \n",w->data);
 // printf("%d \n",w->L->data);
 // printf("%d \n",w->R->data);
  postn(w);
}
