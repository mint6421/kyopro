

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
  vector<string> s(5);
  rep(i,5){
    cin>>s[i];
  }
  vector<vi> dp(n+1,vi(3,inf));
  rep(j,3) dp[0][j]=0;

  rep(j,n){
    vi cnt(3,0);
    rep(i,5){
      if(s[i][j]=='R') cnt[0]++;
      if(s[i][j]=='B') cnt[1]++;
      if(s[i][j]=='W') cnt[2]++;
    }

    dp[j+1][0]=min(dp[j][1]+5-cnt[0],dp[j][2]+5-cnt[0]);
    dp[j+1][1]=min(dp[j][2]+5-cnt[1],dp[j][0]+5-cnt[1]);
    dp[j+1][2]=min(dp[j][0]+5-cnt[2],dp[j][1]+5-cnt[2]);
  }

  cout<<min(dp[n][0],min(dp[n][1],dp[n][2]))<<endl;



}
