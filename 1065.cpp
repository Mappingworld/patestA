#include<cstdio>
const int N=10;
int main() {
long long a;
long long b;
long long c;
long long s;
bool p[N];
int time;
int i=0;
scanf("%d",&time);
for(i=0;i<time;i++){
  scanf("%lld %lld %lld",&a,&b,&c);
  s=a+b;
  if(a>0&&b>0&&s<=0){
     p[i]=true;
     continue;
  }
  if(a<0&&b<0&&s>=0){
     p[i]=false;
     continue;
  }
  if(s>c)
     p[i]=true;
  else
    p[i]=false;
}
for(i=0;i<time;i++){
    if(p[i]==true)
    printf("Case #%d: true\n",i+1);
    else
    printf("Case #%d: false\n",i+1);

}
return 0;
}
