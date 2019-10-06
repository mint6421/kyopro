
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
#define IP pair<int,P>
#define PP pair<P,P>
#define Yes(f){cout<<(f?"Yes":"No")<<endl;}
#define YES(f){cout<<(f?"YES":"NO")<<endl;}

int dp[5010*5010];

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n;
  int g[3][2];

  cin>>n;
  rep(i,2){
    rep(j,3){
      cin>>g[j][i];
    }
  }

  rep(i,n+1){
    dp[i]=n;
  }

  int res=n;
  rep(i,3){
    rep(j,n+1){
      if(j-g[i][0]<0) continue;
      dp[j]=max(dp[j],dp[j-g[i][0]]-g[i][0]+g[i][1]);
      res=max(res,dp[j]);
    }
  }

  rep(i,res+1){
    dp[i]=res;
  }

  int ans=max(n,res);

  rep(i,3){
    rep(j,res+1){
      if(j-g[i][1]<0) continue;
      dp[j]=max(dp[j],dp[j-g[i][1]]-g[i][1]+g[i][0]);
      ans=max(ans,dp[j]);
    }
  }



  cout<<ans<<endl;

}
