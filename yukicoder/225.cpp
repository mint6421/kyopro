
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




vector<vector<int>> solve(string s,string t){
  vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1,inf));
  
  dp[0][0]=0;

  rep(i,s.size()){
    rep(j,t.size()){
      if(s[i]==t[j]) dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]);
      else dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+1);

      dp[i+1][j]=min(dp[i+1][j],dp[i][j]+1);
      dp[i][j+1]=min(dp[i][j+1],dp[i][j]+1);
    }
  }

  return dp;
}

main(){
  int n,m;
  string s,t;
  cin>>n>>m;
  cin>>s>>t;
  s+=' ';
  t+=' ';

  vector<vector<int>> dp = solve(s,t);

  cout<<dp[n][m]<<endl;
}
