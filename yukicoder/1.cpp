
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



main(){
  int n,c,v;
  cin>>n>>c>>v;
  WG<int> es(n*(c+1));
  vector<int> s(v),t(v),y(v),m(v);
  rep(i,v){
    cin>>s[i];
    s[i]--;
  }
  rep(i,v){
    cin>>t[i];
    t[i]--;
  }
  rep(i,v){
    cin>>y[i];
  }
  rep(i,v){
    cin>>m[i];
  }

  rep(i,v){
    FOR(j,0,c-y[i]+1){
      es[s[i]*(c+1)+j+y[i]].PB(edge<int>(t[i]*(c+1)+j,m[i]));
    }
  }

  vector<int> res=dijkstra(es,c);

  int ans=INF;
  rep(i,c+1){
    
    ans=min(ans,res[(n-1)*(c+1)+i]);
  }

  cout<<(ans==INF?-1:ans)<<endl;
}
