
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

  int n,p;
  cin>>n>>p;
  vector<P> v(n);
  rep(i,n){
    cin>>v[i].F>>v[i].S;
  }
  sort(all(v));
  reverse(all(v));
  int dp[p+1]={};
  int ans=0;
  rep(i,n){
    rrep(j,p){
      if(j+v[i].F>p) continue;
      dp[j+v[i].F]=max(dp[j+v[i].F],dp[j]+v[i].S);
    }
    int s=0;
    if(i<n-1) s=v[i+1].S;
    rep(j,p+1){
      ans=max(ans,dp[j]+s);
     
    }
    
    
  }

  cout<<ans<<endl;

}
