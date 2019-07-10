
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

int d[20][20];
int dp[1<<20][20];

main(){
  int n,m;
  cin>>n>>m;

  rep(i,m){
    int a,b,c;
    cin>>a>>b>>c;
    a--;b--;
    d[a][b]=max(d[a][b],c);
    d[b][a]=max(d[b][a],c);
  }

  rep(i,1<<n){
    rep(j,n){
      dp[i][j]=-1;
    }
  }

  rep(i,n){
    dp[1<<i][i]=0;
  }

  int ans=0;

  rep(i,1<<n){
    rep(j,n){
      if(dp[i][j]==-1) continue;
      
      rep(k,n){
        if(i&(1<<k)||d[j][k]==0) continue;
        
        dp[i+(1<<k)][k]=max(dp[i+(1<<k)][k],dp[i][j]+d[j][k]);
      }
      ans=max(ans,dp[i][j]);
    }
  }

  cout<<ans<<endl;
}
