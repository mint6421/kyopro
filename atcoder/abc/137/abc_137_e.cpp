
#include<bits/stdc++.h>
using namespace std;
#define inf 1000000000
#define INF 100000000000000
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


int n,m;
Edges<ll> es;
bool ans=false;



template< typename T >
vector< T > bellman_ford(Edges< T > &edges, int V, int s) {
  const auto lim = numeric_limits< T >::max();
  vector< T > dist(V, lim);
  dist[s] = 0;
  rep(i,V-1) {
    for(auto &e : edges) {
      if(dist[e.src] == lim) continue;
      dist[e.to] = min(dist[e.to], dist[e.src] + e.cost);
    }
  }  

  bool neg[20000]={};

  rep(i,V){
    for(auto &e:edges){
      if(dist[e.src]==lim) continue;
      if(dist[e.to]>dist[e.src]+e.cost){
        dist[e.to]=dist[e.src]+e.cost;
        neg[e.to]=true;
      }
      if(neg[e.src])
        neg[e.to]=true;
    }
  }
  if(neg[V-1])
    return vector<T> ();
  
  return dist;

}

int main(){
  int p;
  cin>>n>>m>>p;
  rep(i,m){
    int a,b,c;
    cin>>a>>b>>c;
    a--;
    b--;
    c-=p;
    es.PB(edge<ll>(a,b,-c));
  }

  vector<ll> s = bellman_ford(es,n,0);
  if(s.empty())
    cout<<-1<<endl;
  else
    cout<<max(0LL,-s[n-1])<<endl;

}
