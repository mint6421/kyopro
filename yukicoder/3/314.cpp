
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

int n;
int dp[1100000][2]={};


main(){
  cin>>n;

  dp[1][0]=1;
  dp[2][0]=1;
  dp[2][1]=1;

  FOR(i,3,n+1){
    dp[i][0]=dp[i-1][1]+dp[i-2][1];
    dp[i][1]=dp[i-1][0];
    dp[i][0]%=M;
    dp[i][1]%=M;
  }
  //cout<<dp[n][0]<<' '<<dp[n][1]<<endl;

  cout<<(dp[n][0]+dp[n][1])%M<<endl;
}
