

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



struct UnionFind {
  vector< int > data;

  UnionFind(int sz) {
    data.assign(sz, -1);
  }

  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }

  int find(int k) {
    if(data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }

  int size(int k) {
    return (-data[find(k)]);
  }
};

int h,w;
char c[2000][2000];

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  cin>>h>>w;
  rep(i,h){
    cin>>c[i];
  }

  UnionFind uf(2000*2000);
  vector<vi> v(h+1,vi(w+1,0));
  rrep(i,h-1){
    rrep(j,w-1){
      if(c[i][j]=='#') continue;
      v[i][j]=1+min(v[i+1][j],min(v[i][j+1],v[i+1][j+1]));
    }
  }

  int q;
  cin>>q;
  vector<PP> res;
  rep(i,q){
    int x,y,l;
    cin>>x>>y>>l;
    x--;y--;
    res.PB(PP(P(l,i),P(x,y)));
  }
  sort(all(res));
  reverse(all(res));
  vi ans(q);

  int t=inf;
  rep(i,q){
    int it=res[i].F.S;
    if(t>res[i].F.F){
      t=res[i].F.F;
      rep(i,h){
        rep(j,w){
          if(v[i][j]>=t&&v[i+1][j]>=t){
            uf.unite(i*w+j,(i+1)*w+j);
          }
          if(v[i][j]>=t&&v[i][j+1]>=t){
            uf.unite(i*w+j,i*w+j+1);
          }
        }
      }
    }
    int x=res[i].S.F,y=res[i].S.S;
    ans[it]=uf.size(x*w+y);
  }

  rep(i,q){
    cout<<ans[i]<<endl;
  }
  

  
}
