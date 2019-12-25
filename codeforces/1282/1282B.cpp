

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

  int q;
  cin>>q;
  while(q--){
    int n,p,k;
    cin>>n>>p>>k;
    vi a(n+1);
    rep(i,n){
      cin>>a[i+1];
    }
    sort(all(a));

    int ans=0;
    vector<P> dp(n+1,P(0,p));
    FOR(i,1,n+1){
      if(i<k){
        dp[i]=P(dp[i-1].F+1,dp[i-1].S-a[i]);
      }else{
        dp[i]=P(dp[i-k].F+k,dp[i-k].S-a[i]);
      }
      //if(i<k)dp[i+k]=P(dp[i].F+i+1,dp[i].S-a[i]);
      //else dp[i+k]=P(dp[i].F+k,dp[i].S-a[i]);
      if(dp[i].S>=0) ans=max(ans,dp[i].F);
    }

    cout<<ans<<endl;
    
  }



}
