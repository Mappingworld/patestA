    //其中使用将字母编号转化成数字编号，以后实现转化时，要注意是否可以进行
    #include<cstdio>
    #include<algorithm>
    #include<cstring>
    #include<vector>
    using namespace std;
    int retr(char* n){
      int m = 1;
      int i = 0;
      int k = 0;
      for(i = 0;i < 3;i++){
        k += (n[i] - 'A') * m;
        m *= 26;
      }
      k = 10 * k + n[3] - '0';
      return k;
    }

    vector<int> vi[26*26*26*26];//开辟空间太大，需要将定义写在main之上
    int main(){
     int stn = 0;
     int tim = 0;

     scanf("%d %d",&stn ,&tim);
     int i = 0 , cid, a;
     char b[5] ;
     int j = 0;
     for(i = 0;i < tim;i++){
        scanf("%d %d",&cid,&a);
        for(j = 0;j < a;j++){
          scanf("%s",b);//&b ? b
          vi[retr(b)].push_back(cid);
        }
     }
     int id = 0;
     for(int i = 0; i < stn; i++) {
            scanf("%s", b);
            id = retr(b);
            sort(vi[id].begin(), vi[id].end());
            printf("%s %lu", b, vi[id].size());//这里可以在函数读取时输出!!!!可以这么写
            for(int j = 0; j < vi[id].size(); j++)
                printf(" %d", vi[id][j]);
            printf("\n");
        }
    }
