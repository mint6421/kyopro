
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
  for(int i=1;i<g.size();i++){
    tsort_dfs(i,graph,visited,g);
  }
  reverse(all(graph));
  return graph;
}


main(){
  int n;
  cin>>n;
  UG es(n+1);
  int a[200000];
  FOR(i,2,n+1){
  
    cin>>a[i];  
    es[a[i]].PB(i);

  }

  vector<int> v=tsort(es);
  reverse(all(v));

  /*
  rep(i,v.size()){
    cout<<v[i]<<' ';
  }
  cout<<endl;
  */

  int dp[200000]={};
  

  rep(i,v.size()){
    int k=v[i];
    int res=0;
    vector<int> b;
    for(auto e:es[k]){
      b.PB(dp[e]);
    }
    sort(all(b));
    for(auto e:b){
      res=max(res+1,e);
    }
    dp[k]=res+1;

  }
  FOR(i,1,n+1){
//    cout<<" "<<dp[i]<<endl;
  }
  cout<<dp[1]-1<<endl;
  
}
