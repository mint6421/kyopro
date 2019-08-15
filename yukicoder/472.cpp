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

int dp[2][15010];

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n,p;
  cin>>n>>p;
  vector<vi> v(n,vi(4));

  rep(i,n){
    rep(j,4){
      if(j==3) v[i][j]=1;
      else cin>>v[i][j];
    }
  }

  rep(i,2){
    rep(j,p+1){
      dp[i][j]=inf;
    }
  }

  dp[0][0]=0;

  rep(i,n){
    rep(j,p+1){
      dp[(i+1)%2][j]=inf;
      rep(k,4){
        if(j-k<0) break;
        dp[(i+1)%2][j]=min(dp[(i+1)%2][j],dp[i%2][j-k]+v[i][k]);
        //cout<<i<<' '<<j<<' '<<dp[(i+1)%2][j]<<endl;
      }
    }
  }


  printf("%.10lf\n",(double)dp[n%2][p]/(double)n);
  

}

