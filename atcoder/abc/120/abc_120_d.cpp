
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

  int n,m;
  cin>>n>>m;
  int res=n*(n-1)/2;
  UnionFind uf(n);
  vector<P> v;
  rep(i,m){
    int a,b;
    cin>>a>>b;
    a--;b--;
    v.PB(P(a,b));
  }

  reverse(all(v));
  vi ans;
  rep(i,m){
    ans.PB(res);
    //cout<<res<<endl;
    int a=v[i].F,b=v[i].S;
    if(uf.find(a,b)) continue;
    res-=uf.size(a)*uf.size(b);
    //cout<<uf.size(a)<<' '<<uf.size(b)<<endl;
    uf.unite(a,b);
  }

  rep(i,m){
    cout<<ans[m-i-1]<<endl;
  }

}
