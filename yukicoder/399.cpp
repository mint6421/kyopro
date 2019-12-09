

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


int dfs(int k,int p,vi &cnt,WG<int> &es){
  int res=0;
  for(auto e:es[k]){
    if(e.to==p) continue;
    res+=dfs(e.to,k,cnt,es);
  }
  if(k) cnt[p]+=cnt[k];

  return res+(cnt[k]*(cnt[k]+1)/2);
}


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n;
  cin>>n;
  WG<int> es(n);
  rep(i,n-1){
    int a,b;
    cin>>a>>b;
    a--;b--;
    es[a].PB(edge<int>(b,1));
    es[b].PB(edge<int>(a,1));
  }

  LCA lca(n,es);
  lca.construct();

  vi cnt(n,0);
  vi next(n,0);
  next[0]=-1;
  queue<P> q1;
  q1.push(P(0,-1));
  
  while(q1.size()){
    P p=q1.front(); q1.pop();
    for(auto e:es[p.F]){
      if(e.to==p.S) continue;
      next[e.to]=p.F;
      q1.push(P(e.to,p.F));
    }
  }
  int q;
  cin>>q;
  while(q--){
    int a,b;
    cin>>a>>b;
    a--;b--;
    int c=lca.lca(a,b);
    cnt[a]++;
    cnt[b]++;
    cnt[c]--;
    if(c)cnt[next[c]]--;
    
    //cout<<a<<' '<<b<<' '<<c<<endl;
  }

  
   
  cout<<dfs(0,-1,cnt,es)<<endl;

  /*
  rep(i,n){
    cout<<cnt[i]<<' ';
  }
  cout<<endl;
  */

      
}
