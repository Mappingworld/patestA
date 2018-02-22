//贪心：总是以单价最高的出售，获利最大
#include<cstdio>
#include<algorithm>
struct p{
  double amout;
  double price;
  double dan;
} kin[1010];

bool qq(p a,p b){
  return a.dan > b.dan;
}

int main(){
  int km ;double zong;
  int i = 0;
  scanf("%d %lf",&km,&zong);
  for(i = 0;i < km;i++){
    scanf("%lf",&kin[i].amout);
  }
  for(i = 0;i < km;i++){
    scanf("%lf",&kin[i].price);
    kin[i].dan = kin[i].price/kin[i].amout;
  }
  std::sort(kin,kin+km,qq);
   for(i = 0;i < km;i++){
   // printf("%lf %lf %lf \n",kin[i].amout,kin[i].price,kin[i].dan);

   }
  int sig = 0;
  double t = 0;
  i = 0;
  while(zong > 0){
    if(kin[i].amout >= zong){
        sig = 1;
        break;
    }
    if(kin[i].amout < zong){
        zong = zong - kin[i].amout;
        i++;
    }
  }
  if(sig == 1){
     t = zong * kin[i].dan;
     i--;
  }
  int j = 0;
  for(j = 0;j <=i;j++){
     t += kin[j].price;
  }
  printf("%.2lf",t);
}
