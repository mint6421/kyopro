
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
#define PL pair<P,int>
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
  sort(all(es),[](const edge<T> & a,const edge<T> &b){
      return (a.cost < b.cost);
      });

  Edges<T> res;
  Edges<int> t;
  UnionFind uf(n);
  T min_cost = 0;

  for(auto &e:es) {
    if(uf.unite(e.src,e.to)) {
      min_cost += e.cost;
      res.PB(e);
    }
    else{
      t.PB(e);
    }
  }

  es = t;
  return res;
}


multiset<PL> s;
WG<int> et;

bool f(int sr,int g,int r,int k){
  if(sr==g){
//    cout<<sr<<' '<<g<<endl;
    return true;
  }

  for(auto e:et[sr]){
    if(e.to==r) continue;
    bool b = f(e.to,g,sr,k);
    if(b){
//      cout<<" "<<sr<<' '<<e.to<<' '<<k<<endl;
      if(e.cost==k){
        int t = s.size();
        PL a(P(sr,e.to),e.cost),b(P(e.to,sr),e.cost);
        auto it = s.find(a);
        if(it!=s.end())
          s.erase(a);
        it = s.find(b);
        if(it!=s.end())
          s.erase(b);
//        cout<<t<<' '<<s.size()<<endl;
      }
     return true; 
    }
  }
  return false;
}


main(){
  int n,m;
  cin>>n>>m;
  Edges<int> es;
  rep(i,m){
    int a,b,c;
    cin>>a>>b>>c;
    a--;b--;
    es.PB(edge<int>(a,b,c));
  }

  Edges<int> tree = kruskal(es,n);
//  cout<<tree.size()<<endl;
  et.resize(n);
  for(auto e:tree){
//    cout<<" "<<e.src<<' '<<e.to<<' '<<e.cost<<endl;
    et[e.src].PB(edge<int>(e.to,e.cost));
    et[e.to].PB(edge<int>(e.src,e.cost));
    s.insert(PL(P(e.src,e.to),e.cost));
  }


  for(auto e:es){
    f(e.src,e.to,-1,e.cost);
  }
  


  int ans=0;
  for(auto e:s){
    ans+=e.S;
  }
  cout<<s.size()<<' '<<ans<<endl;

}
