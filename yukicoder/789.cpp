
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
#define PI 3.14159265
#define F first
#define S second
#define PB push_back
#define EB emplace_back
#define int ll
#define vi vector<int>
#define PP pair<int,P>



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
    seg[k] += x;
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

int n;
map<int,int> mp;
vector<PP> v;

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin>>n;
  rep(i,n){
    int a,b,c;
    cin>>a>>b>>c;
    v.PB(PP(a,P(b,c)));
    mp[b]=0;
    if(a==1) mp[c]=0;
  }

  int c=0;
  for(P p:mp){
    mp[p.F]=c++;
  }

  int ans=0;
  segTree<int> seg(c,[](int a,int b){return a+b;},0);
  rep(i,n){
    int x=mp[v[i].S.F];
    //cout<<x<<' '<<y<<endl;
    if(v[i].F==0){
      seg.update(x,v[i].S.S);
    }else{
      int y=mp[v[i].S.S];
      ans+=seg.get(x,y+1);
      //cout<<ans<<endl;
   }
  }

  cout<<ans<<endl;


}
