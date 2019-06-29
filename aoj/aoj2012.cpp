
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



void f(int n,int m,int l,int k,int a,int h){
  vector<bool> fr(n,false);
  WG<int> es(n*(m+1));

  fr[a]=true;
  fr[h]=true;
  rep(i,l){
    int t;
    cin>>t;
    fr[t]=true;
  }

  rep(i,k){
    int x,y,t;
    cin>>x>>y>>t;
    FOR(j,t,m+1){
      int xk=x*(m+1)+j-t;
      int yk=y*(m+1)+j-t;
      es[x*(m+1)+j].PB(edge<int>(yk,t));
      es[y*(m+1)+j].PB(edge<int>(xk,t));
    }
  }

  rep(i,n){
    rep(j,m){
      if(fr[i]){
        es[i*(m+1)+j].PB(edge<int>(i*(m+1)+j+1,1));
      }
    }
  }
  vector<int> dist = dijkstra(es,a*(m+1)+m);
  int res=INF;
  rep(i,m+1){
    res=min(res,dist[h*(m+1)+i]);
  }

  if(res==INF) cout<<"Help!"<<endl;
  else cout<<res<<endl;
}

main(){
  int n,m,l,k,a,h;

  while(true){
    cin>>n>>m>>l>>k>>a>>h;
    if(n==0) break;
    f(n,m,l,k,a,h);
  }
}
