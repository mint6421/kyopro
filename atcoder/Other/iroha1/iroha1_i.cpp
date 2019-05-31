
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
#define PP pair<P,int>
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
  int n,m,k;
  cin>>n>>m>>k;
  WG<int> es(n+1);
  rep(i,m){
    int a,b,c;
    cin>>a>>b>>c;
    es[a].PB(edge<int>(b,c));
    es[b].PB(edge<int>(a,c));
  }

  priority_queue<P,vector<P>,greater<P>> q;
  vector<int> d(n+1,inf);
  vector<int> co(n+1,0);
  d[1]=0;
  q.push(P(0,1));

  while(!q.empty()){
    P p=q.top(); q.pop();
    int v=p.S;
    if(d[v]<p.F) continue;
    for(auto e:es[v]){
      int c = (co[v]==e.cost?0:1);
      if(d[e.to]>d[v]+c){
        d[e.to]=d[v]+c;
        co[e.to]=e.cost;
        q.push(P(d[e.to],e.to));
      }
    }
  }


  cout<<(d[n]==inf?-1:d[n]*k)<<endl;
}
