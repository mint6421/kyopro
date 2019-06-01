
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


main(){
  int n;
  cin>>n;
  UG es(n);
  vector<P> v(n);
  rep(i,n){
    v[i].S=i;
  }
  rep(i,n-1){
    int a,b;
    cin>>a>>b;
    a--; b--;
    v[a].F++;
    v[b].F++;
    es[a].PB(b);
    es[b].PB(a);
  }

  vector<int> c(n);
  rep(i,n){
    cin>>c[i];
  }

  sort(all(v));
  sort(all(c));
  reverse(all(c));
  vector<int> res(n,-1);

  queue<int> q;
  int t=0;
  q.push(v[0].S);
  while(!q.empty()){
    int x=q.front(); q.pop();
    //cout<<x<<endl;
    if(res[x]!=-1) continue;
    res[x]=c[t];
    t++;
    for(auto e:es[x]){
      q.push(e);
    }
  }


  int ans=0;

  rep(i,n){
    for(auto e:es[i]){
      ans+=min(res[i],res[e]);
    }
  }

  cout<<ans/2<<endl;
  rep(i,n){
    cout<<res[i]<<' ';
  }
  cout<<endl;

}
