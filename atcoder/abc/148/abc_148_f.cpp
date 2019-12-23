

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
int Madd(int x,int y) {return (x+y)%M;}
int Msub(int x,int y) {return (x-y+M)%M;}
int Mmul(int x,int y) {return (x*y)%M;}



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


void dfs(int k,int p,vi &ret,WG<int> &es){
  for(auto e:es[k]){
    if(e.to==p) continue;
    ret[e.to]=ret[k]+1;
    dfs(e.to,k,ret,es);
  }

}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n,u,v;
  cin>>n>>u>>v;
  u--;v--;
  WG<int> es(n);
  rep(i,n-1){
    int a,b;
    cin>>a>>b;
    a--;b--;
    es[a].PB(edge<int>(b,1));
    es[b].PB(edge<int>(a,1));
  }

  vi distu(n,0);
  vi distv(n,0);

  dfs(u,-1,distu,es);
  dfs(v,-1,distv,es);
  

  int ans=0;
  rep(i,n){
    if(distu[i]<distv[i]) ans=max(ans,distv[i]);
  }


  cout<<ans-1<<endl;


}
