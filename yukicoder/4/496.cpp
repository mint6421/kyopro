
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
#define PP pair<P,int>


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);


  int gx,gy,n,f;
  cin>>gx>>gy>>n>>f;
  vector<PP> v;
  v.PB(PP(P(0,0),0));

  rep(i,n){
    int x,y,c;
    cin>>x>>y>>c;
    v.PB(PP(P(x,y),c));
  }

  int dp[600][600];
  rep(i,600)rep(j,600) dp[i][j]=inf;

  dp[0][0]=0;
  rep(i,gy+1){
    rep(j,gx+1){
      dp[i+1][j]=min(dp[i+1][j],dp[i][j]+f);
      dp[i][j+1]=min(dp[i][j+1],dp[i][j]+f);
    }
  }

  for(PP p:v){
    int x=p.F.F,y=p.F.S,c=p.S;

    RFOR(i,gy,y){
      RFOR(j,gx,x){
        dp[i][j]=min(dp[i][j],dp[i-y][j-x]+c);
      }
    }
  }

  cout<<dp[gy][gx]<<endl;

}
