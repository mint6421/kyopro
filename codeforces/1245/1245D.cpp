
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



struct UnionFind
{

  vector<int> par;
  vector<int> sizes;

  UnionFind(int n) : par(n), sizes(n, 1) {
    rep(i,n) par[i] = i;
  }

  int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]); 
  }

  bool unite(int x, int y) {

    x = find(x);
    y = find(y);

    if (x == y) return false;

    if (sizes[x] < sizes[y]) swap(x, y);

    par[y] = x;
    sizes[x] += sizes[y];

    return true;
  }

  int size(int x) {
    return sizes[find(x)];
  }
};


template<typename T>
Edges<T> kruskal(Edges<T> &es,int n) {
  //cout<<es.size()<<endl;
  
  sort(all(es),[](const edge<T> & a,const edge<T> &b){
      return (a.cost < b.cost);
      });


  UnionFind uf(n);
  Edges<int> res;
  T min_cost = 0;

  for(auto &e:es) {
    if(uf.unite(e.src,e.to)) {
      min_cost += e.cost;
      res.PB(e);
    }
  }

  return res;
}


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n;
  cin>>n;
  vector<P> v(n);
  rep(i,n){
    cin>>v[i].F>>v[i].S;
  }

  vi c(n);
  rep(i,n){
    cin>>c[i];
  }

  vi k(n);
  rep(i,n){
    cin>>k[i];
  }

  Edges<int> es;

  rep(i,n){
    es.PB(edge<int>(0,i+1,c[i]));
    es.PB(edge<int>(i+1,0,c[i]));
    //cout<<c[i]<<endl;
  }

  rep(i,n){
    FOR(j,i+1,n){
      int cost=(k[i]+k[j])*(abs(v[i].F-v[j].F)+abs(v[i].S-v[j].S));
      //cout<<cost<<endl;
      es.PB(edge<int>(i+1,j+1,cost));
      es.PB(edge<int>(j+1,i+1,cost));
    }
  }

  Edges<int> res=kruskal(es,n+1);

  int ans=0;
  vi build;
  vector<P> line;
  rep(i,res.size()){
    ans+=res[i].cost;
    if(res[i].src==0) build.PB(res[i].to);
    else if(res[i].to==0) build.PB(res[i].src);
    else line.PB(P(res[i].src,res[i].to));
  }

  cout<<ans<<endl;

  cout<<build.size()<<endl;
  rep(i,build.size()){
    if(i) cout<<' ';
    cout<<build[i];
  }
  cout<<endl;

  cout<<line.size()<<endl;
  rep(i,line.size()){
    cout<<line[i].F<<' '<<line[i].S<<endl;
  }


}
