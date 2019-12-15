

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
struct WeightedUnionFind {
  vector< int > data;
  vector< T > ws;

  WeightedUnionFind() {}

  WeightedUnionFind(int sz) : data(sz, -1), ws(sz) {}

  int find(int k) {
    if(data[k] < 0) return k;
    auto par = find(data[k]);
    ws[k] += ws[data[k]];
    return data[k] = par;
  }

  T weight(int t) {
    find(t);
    return ws[t];
  }

  bool unite(int x, int y, T w) {
    w += weight(x);
    w -= weight(y);
    x = find(x), y = find(y);
    if(x == y) return false;
    if(data[x] > data[y]) {
      swap(x, y);
      w *= -1;
    }
    data[x] += data[y];
    data[y] = x;
    ws[y] = w;
    return true;
  }

  T diff(int x, int y) {
    return weight(y) - weight(x);
  }
};

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n,q;
  cin>>n>>q;
  WeightedUnionFind<int> uf(n);
  while(q--){
    int t;
    cin>>t;
    if(t==0){
      int x,y,z;
      cin>>x>>y>>z;
      uf.unite(x,y,z);
    }else{
      int x,y;
      cin>>x>>y;
      if(uf.find(x)==uf.find(y))
        cout<<uf.diff(x,y)<<endl;
      else
        cout<<'?'<<endl;
    }
  }


}
