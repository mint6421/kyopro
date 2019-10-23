
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

int n;
int a[210000],b[210000],c;
int dp[210000][2];

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  cin>>n>>c;
  rep(i,n-1){
    cin>>a[i];
   
  }
  rep(i,n-1){
    cin>>b[i];
   
  }

  rep(i,n){
    rep(j,2){
      dp[i][j]=inf;
    }
  }

  dp[0][0]=0;
  dp[0][1]=c;

  rep(i,n){
    cout<<min(dp[i][0],dp[i][1])<<' ';
    //cout<<a[i]<<' '<<b[i]<<endl;
    dp[i+1][0]=min(dp[i+1][0],dp[i][0]+a[i]);
    dp[i+1][0]=min(dp[i+1][0],dp[i][1]+a[i]);
    dp[i+1][1]=min(dp[i+1][1],dp[i][1]+b[i]);
    dp[i+1][1]=min(dp[i+1][1],dp[i][0]+b[i]+c);
  }
  cout<<endl;


}
