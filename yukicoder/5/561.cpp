
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



signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n,d;
  cin>>n>>d;
  int a[110][2];
  int dp[110][2]={};

  rep(i,n){
    cin>>a[i+1][0]>>a[i+1][1];
  }

  dp[1][0]=a[1][0];
  dp[1][1]=max(a[1][1]-d,0LL);

  FOR(i,2,n+1){
    dp[i][0]=max(dp[i-1][0]+a[i][0],dp[i-1][1]+a[i][0]-d);
    dp[i][1]=max(dp[i-1][1]+a[i][1],dp[i-1][0]+a[i][1]-d);
  }

  /*
  FOR(i,1,n+1){
    cout<<dp[i][0]<<' '<<dp[i][1]<<endl;
  }
  */

  cout<<max(dp[n][0],dp[n][1])<<endl;


}
