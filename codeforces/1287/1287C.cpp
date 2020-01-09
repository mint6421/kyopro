

#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX
#define INF LLONG_MAX
#define ll long long
#define ull unsigned long long
#define M (int)(1e9+7)
#define P pair<int,int>
#define FOR(i,m,n) for(int i=(int)m;i<(int)n;i++)
#define RFOR(i,m,n) for(int i=(int)m;i>=(int)n;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,n,0)
#define all(a) a.begin(),a.end()
const int vx[4] = {0,1,0,-1};
const int vy[4] = {1,0,-1,0};
#define F first
#define S second
#define PB push_back
#define EB emplace_back
#define int ll
#define vi vector<int>
#define IP pair<int,P>
#define PI pair<P,int>
#define PP pair<P,P>
#define Yes(f){cout<<(f?"Yes":"No")<<endl;}
#define YES(f){cout<<(f?"YES":"NO")<<endl;}


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n;
  cin>>n;
  vi a(n+1);
  FOR(i,1,n+1){
    cin>>a[i];
    if(a[i]==0) a[i]=-1;
    else a[i]%=2;
  }

  vector<vector<vi>> dp(n+1,vector<vi>(n+1,vi(2,inf)));

  dp[0][0][0]=0;
  dp[0][0][1]=0;
  FOR(i,1,n+1){
    rep(j,i+1){
      if(j&&a[i]!=1){
        dp[i][j][0]=min(dp[i-1][j-1][0],dp[i-1][j-1][1]+1);
      }
      if(a[i]!=0){
        dp[i][j][1]=min(dp[i-1][j][0]+1,dp[i-1][j][1]);
      }
    }
  }

  cout<<min(dp[n][n/2][0],dp[n][n/2][1])<<endl;


}
