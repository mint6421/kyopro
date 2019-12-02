
#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX
#define INF LLONG_MAX
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
#define vi vector<int>

int dp[3100][3100];

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n,m,k;
  cin>>n>>m>>k;
  vector<P> v(m);
  rep(i,m){
    cin>>v[i].F>>v[i].S;
  }

  dp[0][1]=1;
  rep(i,k){
    FOR(j,1,n+1){
      dp[i][j]+=dp[i][j-1];
      dp[i][j]%=M;
    }

    rep(j,m){
      if(!dp[i][v[j].F]) continue;
      int t=(dp[i][v[j].S]-dp[i][v[j].F-1]+M)%M;
      dp[i+1][v[j].F]+=t;
      dp[i+1][v[j].F]%=M;
      dp[i+1][v[j].S+1]+=M-t;
      dp[i+1][v[j].S+1]%=M;
    }

    FOR(j,1,n+1){
      dp[i+1][j]+=dp[i+1][j-1];
      dp[i+1][j]%=M;
    }
  }


  cout<<dp[k][n]<<endl;
  

}
