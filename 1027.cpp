/*65A97a*/
#include<cstdio>
int main(){
int m[9]={0};
int i=0;
for(i=0;i<3;i++){
scanf("%d",&m[i]);
}
int j=3;
for(i=0;i<3;i++){
m[j++]=m[i]/13;
m[j++]=m[i]%13;
}
printf("#");
for(i=0;i<6;i++){
    if(m[i+3]>9){
        printf("%c",m[i+3]-10+65);
    }
    else
        printf("%d",m[i+3]);

}
return 0;
}
