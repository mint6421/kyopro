
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

int dp[2100][2100];
vi es[2100];

vi dfs(int v,int p){
  vi ret(1,1);
  for(int next:es[v]){
    if(next==p) continue;
    vi tmp = dfs(next,v);
    int n=ret.size();
    int m=tmp.size();
    vi nret(n+m-1,0);
    rep(i,n)rep(j,m){
      int res=(ret[i]*tmp[j])%M;
      nret[i+j]+=res;
      nret[i+j]%=M;
    }
    ret=nret;
  }
  ret.PB(1);
  return ret;
}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n,k;
  cin>>n>>k;
  rep(i,n-1){
    int a,b;
    cin>>a>>b;
    es[a].PB(b);
    es[b].PB(a);
  }

  vi ans=dfs(0,-1);
  cout<<ans[k]<<endl;


}
