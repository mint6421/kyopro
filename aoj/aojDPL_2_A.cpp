
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




template< typename T >
struct edge {
  int src, to;
  T cost;

  edge(int to, T cost) : src(-1), to(to), cost(cost) {}

  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

  edge &operator=(const int &x) {
    to = x;
    return *this;
  }

  operator int() const { return to; }
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WG = vector< Edges< T > >;
using UG = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;



main(){
  int v,e;
  cin>>v>>e;
  WG<int> es(v);
  vector<vector<int>> dp((1<<v),vector<int>(v,INF));
  vector<int> cost(v,INF);

  rep(i,e){
    int s,t,d;
    cin>>s>>t>>d;
    es[s].PB(edge<int>(t,d));
    if(t==0){
      cost[s]=min(cost[t],d);
    }
  }
  dp[1][0]=0;
  rep(i,(1<<v)){
    rep(j,v){
      if(dp[i][j]==inf) continue;
      for(auto et:es[j]){
        if(i&(1<<et.to)) continue;
        dp[i|(1<<et.to)][et.to]=min(dp[i|(1<<et.to)][et.to],dp[i][j]+et.cost);
      }
    }
  }

  int ans=INF;
  rep(i,v){
    if(dp[(1<<v)-1][i]!=INF&&cost[i]!=INF)
      ans=min(ans,dp[(1<<v)-1][i]+cost[i]);
    }

  cout<<((ans==INF)?-1:ans)<<endl;

}
