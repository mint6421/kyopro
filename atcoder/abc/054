
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

int n,ma,mb;
int dp[50][510][510];
int a[50],b[50],c[50];

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  cin>>n>>ma>>mb;
  rep(i,50){
    rep(j,510){
      rep(k,510){
        dp[i][j][k]=inf;
      }
    }
  }

  rep(i,n){
    cin>>a[i]>>b[i]>>c[i];
  }

  dp[0][0][0]=0;
  rep(i,n){
    rep(j,450){
      rep(k,450){
        dp[i+1][j][k]=min(dp[i+1][j][k],dp[i][j][k]);
        if(j+a[i]>400||k+b[i]>400) continue;
        dp[i+1][j+a[i]][k+b[i]]=min(dp[i+1][j+a[i]][k+b[i]],dp[i][j][k]+c[i]);
      }
    }
  }

  int ans=inf;
  FOR(i,1,400){
    if(ma*i>400||mb*i>400) break;
    ans=min(ans,dp[n][ma*i][mb*i]);
  }

  cout<<(ans==inf?-1:ans)<<endl;



}
