
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


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n,m;
  cin>>n>>m;
  vi a(m);
  int c[1100]={};

  rep(i,m){
    int b;
    cin>>a[i]>>b;
    int s=0;
    rep(i,b){
      int d;
      cin>>d;
      d--;
      s+=(1<<d);
    }
    c[i]=s;
  }

  int dp[(1<<15)];
  rep(i,(1<<15)){
    dp[i]=INF;
  }
  dp[0]=0;


  rep(i,(1<<n)){
    if(dp[i]==INF) continue;
    rep(j,m){
      dp[i|c[j]]=min(dp[i|c[j]],dp[i]+a[j]);
      //cout<<i<<' '<<j<<' '<<(i|c[j])<<' '<<c[j]<<endl;
    }
  }

  rep(i,1<<n){
    //cout<<dp[i]<<endl;
  }

  cout<<(dp[(1<<n)-1]==INF?-1:dp[(1<<n)-1])<<endl;

}
