
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


int n,m;
UG g;
vector<P> es;
bool flag=true;
vector<int> c;

void dfs(int v,int w){
  c[v]=w;
  for(auto e:g[v]){
    if(c[e]==-1){
      dfs(e,w^1);
    }
    else{
      if(c[e]==c[v]){
        flag=false;
      }
    }
  }
}


main(){
  cin>>n>>m;
  g.resize(n);
  rep(i,m){
    int x,y;
    cin>>x>>y;
    x--;y--;
    g[x].PB(y);
    g[y].PB(x);
    es.PB(P(x,y));
  }

  
  c=vector<int>(n,-1);
  dfs(0,0);

  if(!flag){
    cout<<"NO"<<endl;
    return 0;
  }

  cout<<"YES"<<endl;
  rep(i,m){
    cout<<(c[es[i].F]<c[es[i].S]);
  }
  cout<<endl;

}
