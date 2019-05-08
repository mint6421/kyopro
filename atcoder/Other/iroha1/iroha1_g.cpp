
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


int n,m,k;
int a[400];
int dp[1000][1000];

main(){
  cin>>n>>m>>k;
 
  n++;
  m++;
  FOR(i,1,n){
    cin>>a[i];
  }
  rep(i,400){
    rep(j,400){
      dp[i][j]=-1;
    }
  }
  dp[0][0]=0;
  rep(i,n){
    rep(j,m){
      FOR(l,1,k+1){
        if(dp[i][j]==-1) continue;
        if(i+l<=n)
          dp[i+l][j+1]=max(dp[i+l][j+1],dp[i][j]+a[i]);
      }
    }
  }

  cout<<dp[n][m]<<endl;
}
