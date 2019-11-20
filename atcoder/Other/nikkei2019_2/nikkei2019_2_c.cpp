

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

  int n;
  cin>>n;
  
  vi a(n),b(n);
  vector<P> aa(n),bb(n);
  rep(i,n){
    cin>>a[i];
    aa[i]=P(a[i],i);
  }
  rep(i,n){
    cin>>b[i];
    bb[i]=P(b[i],i);
  }

  sort(all(aa));
  sort(all(bb));

  rep(i,n){
    if(aa[i].F>bb[i].F){
      Yes(false);
      return 0;
    }
  }

  
  UnionFind uf(n);
  rep(i,n){
    uf.unite(aa[i].S,bb[i].S);
  }

  int cnt=0;
  rep(i,n){
    if(uf.root(i)==i) cnt++;
    if(cnt>1){
      Yes(true);
      return 0;
    }
  }
  

  rep(i,n-1){
    if(aa[i].F<=bb[i+1].F&&aa[i+1].F<=bb[i].F){
      Yes(true);
      return 0;
    }
  }

  Yes(false);



}
