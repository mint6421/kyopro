
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



vector< bool > prime_table(int n) {
  vector< bool > prime(n + 1, true);
  if(n >= 0) prime[0] = false;
  if(n >= 1) prime[1] = false;
  for(int i = 2; i * i <= n; i++) {
    if(!prime[i]) continue;
    for(int j = i + i; j <= n; j += i) {
      prime[j] = false;
    }
  }
  return prime;
}


int dp[11000][21000];

main(){
  int n;
  cin>>n;
  vector<bool> prime = prime_table(n+1);
  vector<int> p;
  rep(i,n+1){
    if(prime[i]) p.PB(i);
  }

  rep(i,p.size()){
    dp[i+1][p[i]]=max(dp[i+1][p[i]],1LL);
    //cout<<p[i]<<"  ";
    rep(j,n+1){
      dp[i+1][j]=max(dp[i][j],dp[i+1][j]);
      if(dp[i][j]==0) continue;
      //cout<<j+p[i]<<' ';
      if(j+p[i]>n) continue;
      dp[i+1][j+p[i]]=max(dp[i+1][j+p[i]],dp[i][j]+1);
    }
    //cout<<endl;
  }

  cout<<(dp[p.size()][n]==0?-1:dp[p.size()][n])<<endl;
}
