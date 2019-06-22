
#include<bits/stdc++.h>
using namespace std;
#define inf 1000000000
#define INF 1000000000000000
#define ll long long
#define ull unsigned long long
#define M (int)(1e9+7)
#define P pair<int,int>
#define PLL pair<ll,ll>
#define FOR(i,m,n) for(int i=(int)m;i<(int)n;i++)
#define RFOR(i,m,n) for(int i=(int)m;i>=(int)n;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,n,0)
#define all(a) a.begin(),a.end()
#define IN(a,n) rep(i,n){ cin>>a[i]; }
const int vx[4] = {0,1,0,-1};
const int vy[4] = {1,0,-1,0};
#define PI 3.14159265
#define F first
#define S second
#define PB push_back
#define EB emplace_back
#define int ll
void init(){
  cin.tie(0);
  ios::sync_with_stdio(false);
}

void f(int n){
  string s[1100];

  rep(i,n){
    cin>>s[i];
  }
  vector<int> v[2100];

  rep(j,2100){
    rep(i,n){
      if(j>=s[i].size()) continue;
      if(s[i][j]=='.'&&'a'<=s[i][j+1]&&s[i][j+1]<='z'){
        s[i][j]='+';
        v[j].PB(i);
      }
    }
  }

  rep(i,2100){
    if(v[i].size()<2) continue;
    rep(j,v[i].size()-1){
      int a=v[i][j],b=v[i][j+1];
      bool flag=false;
      FOR(k,a+1,b){
        if(i>=s[k].size()) continue;
        if(s[k][i]=='.')
          s[k][i]='|';
        else{
          flag=true;
        }
      }
      if(flag){
        FOR(k,a+1,b){
          if(i>=s[k].size()) continue;
          if(s[k][i]=='|')
            s[k][i]='.';
        }
      }
    }
  }
  rep(i,n){
    rep(j,2100){
      if(j>=s[i].size()) continue;
      if(s[i][j]=='.') s[i][j]=' ';
    }
  }

  rep(i,n){
    cout<<s[i]<<endl;
  }
}




main(){
  int n;
  while(true){
    cin>>n;
    if(!n) break;
    f(n);
  }
}
