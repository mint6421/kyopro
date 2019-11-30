

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
struct BIT {
  vector< T > data;

  BIT(int sz) {
    data.assign(++sz, 0);
  }

  T sum(int k) {
    T ret = 0;
    for(++k; k > 0; k -= k & -k) ret=Madd(ret,data[k]);
    return (ret);
  }

  T get(int x,int y){

    return Msub(sum(y),sum(x));
  }

  void add(int k, T x) {
    for(++k; k < data.size(); k += k & -k) data[k]=Madd(data[k],x);
  }
};

template< typename Monoid >
struct segTree {
  using F = function< Monoid(Monoid, Monoid) >;

  int sz;
  vector< Monoid > seg;

  const F f;
  const Monoid M1;

  segTree(int n, const F f, const Monoid &M1) : f(f), M1(M1) {
    sz = 1;
    while(sz < n) sz <<= 1;
    seg.assign(2 * sz, M1);
  }

  void set(int k, const Monoid &x) {
    seg[k + sz] = x;
  }

  void build() {
    for(int k = sz - 1; k > 0; k--) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  void update(int k, const Monoid &x) {
    k += sz;
    seg[k] = x;
    while(k >>= 1) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  Monoid get(int a, int b) {
    Monoid L = M1, R = M1;
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1) L = f(L, seg[a++]);
      if(b & 1) R = f(seg[--b], R);
    }
    return f(L, R);
  }

  Monoid operator[](const int &k) const {
    return seg[k + sz];
  }
};

struct UnionFind
{

  vector<int> par;
  vector<int> sizes;

  UnionFind(int n) : par(n), sizes(n, 1) {
    rep(i,n) par[i] = i;
  }

  int root(int x) {
    if (x == par[x]) return x;
    return par[x] = root(par[x]); 
  }

  bool unite(int x, int y) {

    x = root(x);
    y = root(y);

    if (x == y) return false;

    if (sizes[x] < sizes[y]) swap(x, y);

    par[y] = x;
    sizes[x] += sizes[y];

    return true;
  }

  bool find(int x,int y){
    return root(x)==root(y);
  }

  int size(int x) {
    return sizes[root(x)];
  }
};


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n,m,q;
  cin>>n>>m>>q;
  vector<IP> es;
  rep(i,m){
    int a,b,c;
    cin>>a>>b>>c;
    a--;b--;
    es.PB(IP(c,P(a,b)));
  }

  UnionFind uf(n);  
  BIT<int> bit(n+1);

  sort(all(es));
  vi res(n+1,INF);
  res[1]=0; 
  bit.add(1,n);
  int it=2;

  rep(i,m){
    int l=es[i].F;
    P p=es[i].S;
    if(uf.root(p.F)==uf.root(p.S)) continue;
    bit.add(uf.size(p.F),-uf.size(p.F));
    bit.add(uf.size(p.S),-uf.size(p.S));
    uf.unite(p.F,p.S);
    bit.add(uf.size(p.F),uf.size(p.F));
    //cout<<it<<' '<<bit.get(it-1,n+1)<<endl;
    while(it<=n&&bit.get(it-1,n)==n){
      res[it]=l;
      it++;
      //cout<<it<<endl;
    }
    
    //cout<<uf.size(p.F)<<' '<<uf.size(p.S)<<endl;
    //cout<<"        "<<seg.get(0,n)<<endl;
  }
  /*
  rep(j,n){
    cout<<uf.size(j)<<' ';
  }
  cout<<endl;



  rep(i,n+1){
    cout<<s[i]<<endl;
  }


  rep(i,n){
    //res[i]=min(res[i],res[i+1]);
    cout<<' '<<res[i]<<endl;
  } 
  */

  while(q--){
    int x;
    cin>>x;
    if(x>n||res[x]==INF) cout<<"trumpet"<<endl;
    else cout<<res[x]<<endl;
  }

}
