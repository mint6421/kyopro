
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
void init(){
  cin.tie(0);
  ios::sync_with_stdio(false);
}


int n,m;
int a[600][600];
bool dp[1100][2200];


void f(int k){
  vector<int> v;
  RFOR(i,n,1){
    rep(j,m){
      //cout<<i<<' '<<j<<' '<<k<<endl;
      //cout<<(k^a[i-1][j])<<endl;
      if(dp[i-1][k^a[i-1][j]]){
        v.PB(j+1);
        k=k^a[i-1][j];
        break;
      }
    }
  }

  reverse(all(v));

  rep(i,v.size()){
    if(i) cout<<' ';
    cout<<v[i];
  }

  cout<<endl;
}


int main(){
  cin>>n>>m;
  rep(i,n){
    rep(j,m){
      cin>>a[i][j];
    }
  }

  dp[0][0]=true;

  rep(i,n){
    rep(j,1100){
      if(!dp[i][j]) continue;
      rep(k,m){
        dp[i+1][j^a[i][k]]=dp[i][j];
      }
    }
  }

  rep(j,1100){
    if(j==0) continue;
    if(dp[n][j]){
      cout<<"TAK"<<endl;
      f(j);
      return 0;
    }
  }
  cout<<"NIE"<<endl;
}


