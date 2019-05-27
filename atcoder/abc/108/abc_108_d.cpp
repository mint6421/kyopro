  
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




ll power(ll x,ll k){
  ll ret=1;
  while(k>0){
    if(k&1) (ret*=x) %= M;
    (x*=x) %= M;
    k >>= 1;
  }
  return ret;
}

main(){
  int l;
  cin>>l;
  
  int r;
  rrep(i,30){
    if(l&(1<<i)){
      r=i;
      break;
    }
  }

  WG<int> es(r+1);
  int m=0;
  FOR(i,1,r+1){  
    es[i].PB(edge<int>(i+1,power(2,i-1)));
    es[i].PB(edge<int>(i+1,0));
    m+=2;
  }

  RFOR(t,r,1){
    if(l-power(2,t-1)>=power(2,r)){
      es[t].PB(edge<int>(r+1,l-power(2,t-1)));
      m++;
      l-=power(2,t-1);
    }
  }

  cout<<r+1<<' '<<m<<endl;

  FOR(i,1,r+1){
    for(auto e:es[i]){
      cout<<i<<' '<<e.to<<' '<<e.cost<<endl;
    }
  }



}
