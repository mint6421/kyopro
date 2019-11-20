

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
#define MPlus(x,y) {x=(x+y)%M;}
#define MSub(x,y) {x=(x-y+M)%M;}
#define MMul(x,y) {x=(x*y)%M;}



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


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n,m;
  cin>>n>>m;
  set<int> es[n];
  rep(i,m){
    int a,b;
    cin>>a>>b;
    a--;b--;
    es[a].insert(b);
    es[b].insert(a);
  }
  
  segTree<P> seg(n,[](P a,P b){return min(a,b);},P(inf,inf));
  rep(i,n){
    seg.update(i,P(es[i].size(),i));
  }

  
  vector<vi> node(n);
  map<P,bool> mp;
  while(true){
    P p=seg.get(0,n);
    if(p.F==inf) break;
    //cout<<p.F<<' '<<p.S<<endl;
    for(int x:es[p.S]){
      if(node[p.S].size()%2){
        node[p.S].PB(x);
      }else{
        node[x].PB(p.S);
      }
      es[x].erase(p.S);
      seg.update(x,P(es[x].size(),x));
    }
    seg.update(p.S,P(inf,p.S));
  }

  rep(i,n){
    //cout<<node[i].size()<<endl;
    if(node[i].size()%2){
      cout<<-1<<endl;
      return 0;
    }
  }

  rep(i,n){
    for(int j:node[i]){
      cout<<i+1<<' '<<j+1<<endl;
    }
  }

}
