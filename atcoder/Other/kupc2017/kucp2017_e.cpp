

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

  int n,m;
  cin>>n>>m;
  vi v(n);
  rep(i,n){
    cin>>v[i];
  }

  UnionFind uf(n);
  vector<P> x;
  rep(i,m){
    int a,b;
    cin>>a>>b;
    a--;b--;
    x.PB(P(a,b));
    uf.unite(a,b);
  }

  vector<priority_queue<int>> q(n);
  rep(i,n){
    q[uf.root(i)].push(v[i]);
  }

  vi s(n,0);
  rep(i,m){
    s[uf.root(x[i].F)]++;
  }

  int ans=0;
  rep(i,n){
    rep(j,s[i]){
      if(q[i].empty()) break;
      ans+=q[i].top();
      q[i].pop();
    }
  }

  cout<<ans<<endl;


}
