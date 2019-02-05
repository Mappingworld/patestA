#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
const int a = 10005;
const int b = 105;

struct st{
  string s;
  int sc;
}sts[a];

struct s3{
  string a;
  int b;
};

int num1,num2;

bool cmp(struct st f,struct st t){
   return f.sc != t.sc ? f.sc > t.sc : f.s < t.s;
}

bool cmp1(struct s3 f,struct s3 t){
   return f.b != t.b ? f.b > t.b : f.a < t.a;
}

void w1(string s){
  vector<st> ans;
  for(int i = 0;i < num1;i++){
    if(s[0] == sts[i].s[0])
        ans.push_back(sts[i]);
  }
  sort(ans.begin(),ans.end(),cmp);
  if(ans.size() != 0)
    for(int i = 0;i < ans.size();i++){
      cout << ans[i].s << " " << ans[i].sc << "\n";
    }
  else
    cout << "NA" <<"\n";
}

void w2(string s){
  int g = 0,num = 0;
  for(int i = 0;i < num1;i++){
    if(s == sts[i].s.substr(1,3)){
        g++;
        num += sts[i].sc;
    }

  }
  if(g != 0)
    cout << g << " " << num <<"\n";
   else
    cout << "NA" << "\n";
}

void w3(string s){
   unordered_map<string,int> ans;
   vector<s3> an;
   //cout << "OOOK";
   for(int i = 0;i < num1;i++){
    //cout << sts[i].s.substr(4,9) <<"\n";
    if(s == sts[i].s.substr(4,6)){
        //cout << "OOOK";
        ans[sts[i].s.substr(1,3)]++;
    }
   }
   struct s3 v;
   for (auto it : ans){
       v.a = it.first;
       v.b = it.second;
       an.push_back(v);
   }
   sort(an.begin(),an.end(),cmp1);
   if(an.size() != 0){
     for(int i = 0;i < an.size();i++){
      cout << an[i].a << " " << an[i].b << "\n";
     }
   }
   else
    cout << "NA" << "\n";
    //cout << it.first << " " << it.second << "\n";
}

int main(){
   int t;
   string rs;
   cin >> num1 >> num2;
   for(int i = 0;i < num1;i++){
    cin >> sts[i].s >> sts[i].sc;

   }
   for(int i = 0;i < num2;i++){
    cin >> t >> rs;
    cout << "Case " << i + 1 <<": " << t << " " << rs << "\n";
    if(t == 1)
        w1(rs);
    if(t == 2)
        w2(rs);
    if(t == 3)
        w3(rs);
   }
}

