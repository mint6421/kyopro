
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


template< typename T >
struct edge {
  int src, to;
  T cost;
  int d;

  edge(int to, T cost) : src(-1), to(to), cost(cost) {}

  edge(int to,T cost,int d) : src(-1),to(to),cost(cost),d(d) {}

  //edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

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

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n,m,k;
  cin>>n>>m>>k;
  vi t(n);
  rep(i,n-2){
    cin>>t[i+1];
  }

  WG<int> es(n);

  rep(i,m){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    a--;b--;
    es[a].PB(edge<int>(b,c,d));
    es[b].PB(edge<int>(a,c,d));
  }

  priority_queue<P,vector<P>,greater<P>> q;
  q.push(P(0,0));
  vi res(n,INF);
  res[0]=0;

  while(!q.empty()){
    P p=q.top(); q.pop();
    p.S+=t[p.F];
    for(auto e:es[p.F]){
      int t=((p.S+e.d-1)/e.d)*e.d;
      t+=e.cost;
      if(res[e.to]>t){
        res[e.to]=t;
        q.push(P(e.to,t));
      }
    }
  }

  if(res[n-1]>k){
    cout<<-1<<endl;
  }else{
    cout<<res[n-1]<<endl;
  }

}
