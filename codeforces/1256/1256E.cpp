

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
  vector<P> v(n);
  rep(i,n){
    cin>>v[i].F;
    v[i].S=i;
  }

  sort(all(v));
  vi dp(n+1,inf);
  vi p(n+1,-1);

  dp[0]=0;

  rep(i,n){
    FOR(j,3,6){
      if(i+j>n) break;
      int di=v[i+j-1].F-v[i].F;
      if(dp[i+j]>dp[i]+di){
        p[i+j]=i;
        dp[i+j]=dp[i]+di;
      }
    }
  }

  int cur=n;
  int cnt=0;
  vi t(n);
  while(cur!=0){
    RFOR(i,cur-1,p[cur]){
      t[v[i].S]=cnt;
    }
    cnt++;
    cur=p[cur];
  }

  cout<<dp[n]<<' '<<cnt<<endl;
  rep(i,n){
    cout<<t[i]+1<<' ';
  }
  cout<<endl;

}
