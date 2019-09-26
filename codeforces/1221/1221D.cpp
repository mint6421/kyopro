
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

int dp[300100][4];

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int q;
  cin>>q;
  while(q--){
    int n;
    cin>>n;
    vector<P> v(n);
    rep(i,n){
      cin>>v[i].F>>v[i].S;
    }
    rep(i,n){
      rep(j,4){
        dp[i][j]=INF;
      }
    }
    dp[0][0]=0;
    dp[0][1]=v[0].S;
    dp[0][2]=v[0].S*2;
    dp[0][3]=v[0].S*3;
    FOR(i,1,n){
      rep(j1,4){
        if(dp[i-1][j1]==INF) continue;
        rep(j2,4){
          if(v[i-1].F+j1==v[i].F+j2) continue;
          dp[i][j2]=min(dp[i][j2],dp[i-1][j1]+j2*v[i].S);
        }
      }
    }
    int ans=INF;
    rep(i,4){
      ans=min(ans,dp[n-1][i]);
    }
    cout<<ans<<endl;
  }



}
