
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
#define vi vector<int>

int n;
int dp[1<<16];
int d[16];

main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin>>n;
  rep(i,n){
    cin>>d[i];
  }

  dp[0]=100;
  rep(i,(1<<n)){
    if(dp[i]==0) continue;
    int mx=100;
    rep(j,n){
      if((i&(1<<j))&&d[j]<0) 
        mx+=100;
    }
    rep(j,n){
      if(i&(1<<j)) continue;
      dp[i+(1<<j)]=max(dp[i+(1<<j)],min(mx,dp[i]+d[j]));
    }
  }

  cout<<dp[(1<<n)-1]<<endl;


}



