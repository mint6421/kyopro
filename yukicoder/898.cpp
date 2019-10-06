
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


struct LCA{
  const int MAX_LOG_V = 50;

  vector<vector<int> > G,parent;
  int root=0,V;
  vector<int> depth;
  LCA(){}
  LCA(int V):V(V){init();}
  LCA(int V,WG<int> es):V(V){init();rep(i,V){for(auto e:es[i]){G[i].PB(e.to);}}}

  void init(){
    for(int i=0;i<(int)G.size();i++) G[i].clear();
    G.clear();
    for(int i=0;i<(int)parent.size();i++) parent[i].clear();
    parent.clear();
    depth.clear();
    G.resize(V);
    parent.resize(MAX_LOG_V,vector<int>(V));
    depth.resize(V);
  }

  void add(int u,int v){
    G[u].PB(v);
  }

  void dfs(int v,int p,int d){
    parent[0][v]=p;
    depth[v]=d;
    for(int i=0;i<(int)G[v].size();i++){
      if(G[v][i]!=p) dfs(G[v][i],v,d+1);
    }
  }

  void construct(){
    dfs(root,-1,0);
    for(int k=0;k+1<MAX_LOG_V;k++){
      for(int v=0;v<V;v++){
        if(parent[k][v]<0) parent[k+1][v]=-1;
        else parent[k+1][v]=parent[k][parent[k][v]];
      }
    }
  }

  int lca(int u,int v){
    if(depth[u]>depth[v]) swap(u,v);
    for(int k=0;k<MAX_LOG_V;k++){
      if((depth[v]-depth[u])>>k&1){
        v=parent[k][v];
      }
    }
    if(u==v) return u;
    for(int k=MAX_LOG_V-1;k>=0;k--){
      if(parent[k][u]!=parent[k][v]){
        u=parent[k][u];
        v=parent[k][v];
      }
    }
    return parent[0][u];
  }
};




template< typename T >
vector<T> dijkstra(WG<T> &g,int s){
  const auto lim = numeric_limits<T>::max();
  vector<T> dist(g.size(),lim);
  using Pi = pair<T,int>;
  priority_queue<Pi,vector<Pi>,greater<Pi>> q;
  dist[s] = 0;
  q.emplace(dist[s],s);
  while(!q.empty()){
    T cost;
    int idx;
    tie(cost,idx) = q.top();
    q.pop();
    if(dist[idx] < cost) continue;
    for( auto &e : g[idx]){
      auto next_cost = cost + e.cost;
      if(dist[e.to] <= next_cost) continue;
      dist[e.to] = next_cost;
      q.emplace(dist[e.to],e.to);
    }
  }
  return dist;
}



signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n;
  cin>>n;
  WG<int> es(n);
  rep(i,n-1){
    int a,b,c;
    cin>>a>>b>>c;
    es[a].PB(edge<int>(b,c));
    es[b].PB(edge<int>(a,c));
  }

  LCA lca(n,es);

  lca.construct();
  vi d = dijkstra(es,0);

  int q;
  cin>>q;

  while(q--){
    int a,b,c;
    cin>>a>>b>>c;
    int ans=d[a]+d[b]+d[c];
    ans-=d[lca.lca(a,b)];
    ans-=d[lca.lca(b,c)];
    ans-=d[lca.lca(c,a)];
    cout<<ans<<endl;

  }



}
