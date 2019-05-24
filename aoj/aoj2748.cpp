
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



template< typename G >
struct StronglyConnectedComponents {
  const G &g;
  UG gg, rg;
  vector< int > comp, order, used;

  StronglyConnectedComponents(G &g) : g(g), gg(g.size()), rg(g.size()), comp(g.size(), -1), used(g.size()) {
    for(int i = 0; i < g.size(); i++) {
      for(auto e : g[i]) {
        gg[i].emplace_back((int) e);
        rg[(int) e].emplace_back(i);
      }
    }
  }

  int operator[](int k) {
    return comp[k];
  }

  void dfs(int idx) {
    if(used[idx]) return;
    used[idx] = true;
    for(int to : gg[idx]) dfs(to);
    order.push_back(idx);
  }

  void rdfs(int idx, int cnt) {
    if(comp[idx] != -1) return;
    comp[idx] = cnt;
    for(int to : rg[idx]) rdfs(to, cnt);
  }

  void build(UG &t) {
    for(int i = 0; i < gg.size(); i++) dfs(i);
    reverse(begin(order), end(order));
    int ptr = 0;
    for(int i : order) if(comp[i] == -1) rdfs(i, ptr), ptr++;

    t.resize(ptr);
    for(int i = 0; i < g.size(); i++) {
      for(auto &to : g[i]) {
        int x = comp[i], y = comp[to];
        if(x == y) continue;
        t[x].push_back(y);
      }
    }
  }
};






void tsort_dfs(int u,vector<int> &graph,bool visited[],UG &g){

  if(visited[u]) return;
  visited[u] = true;
  for(int i=0;i<g[u].size();i++){
    tsort_dfs(g[u][i],graph,visited,g);
  }
  graph.PB(u);
}


vector<int> tsort(UG &g){
  vector<int> graph;
  bool visited[110000] = {};
  for(int i=0;i<g.size();i++){
    tsort_dfs(i,graph,visited,g);
  }
  reverse(all(graph));
  return graph;
}


void dfs(int k,UG es,bool b[]){ 
  b[k]=true;
  for(auto e:es[k]){
    if(b[e]) continue;
    dfs(e,es,b);
  }
}


void f(int n){
  
  UG es(n);
  double v[110];

  rep(i,n){
    double p;
    int m;
    cin>>p>>m;
    v[i]=p;
   
    rep(j,m){
      int a;
      cin>>a;
      a--;
      es[i].PB(a);
    }
  }

  StronglyConnectedComponents<UG> scc(es);
  UG et;
  scc.build(et);

  double a[1100]={};
 

  rep(i,n){
    a[i]=1;
  }

  rep(i,n){
    a[scc[i]]*=v[i];
  }

  double ans=1;
  vector<int> w=tsort(es);
  

  bool b[1100]={};
  rep(i,n){
    int t=w[i];
//    cout<<t<<endl;
    if(b[t]) continue;
    ans=ans*(1-a[scc[t]]);
    dfs(t,es,b);
  }

 
  printf("%.20lf\n",ans);

}


main(){
  int n;
  while(true){
    cin>>n;
    if(!n) break;
    f(n);
  }
}
