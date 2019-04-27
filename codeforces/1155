
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
void init(){
  cin.tie(0);
  ios::sync_with_stdio(false);
}

int n;
ll x;
ll a[310000];
ll dp[310000][10][10];


int main(){
  cin>>n>>x;

  rep(i,n){
    cin>>a[i];
  }

  rep(i,n+1){
    rep(j,3){
      rep(k,3){
        dp[i][j][k]=-INF;
      }
    }
  }

  dp[0][0][0]=0;

  rep(i,n+1){
    rep(j,3){
      rep(k,3){
        dp[i][j][k+1]=max(dp[i][j][k+1],dp[i][j][k]);
        dp[i][j+1][k]=max(dp[i][j+1][k],dp[i][j][k]);

        if(j==1){
          if(k==1)
            dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]+a[i]*x);
          else
            dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]+a[i]);
        }
        else
          dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]);

      }
    }
  }

  cout<<dp[n][2][2]<<endl;
}
