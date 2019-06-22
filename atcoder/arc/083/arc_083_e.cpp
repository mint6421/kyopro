
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


int n;
UG es(1100);
int x[1100];
P dp[1100];

bool f(int k){
  int sum=0;
  bitset<5100> b;
  b[0]=1;
  for(int e:es[k]){
    P a=dp[e];
    b= (b<<a.F)|(b<<a.S);
    sum+=(a.F+a.S);
  }
  rrep(i,x[k]){
    if(b[i]){
      dp[k]=P(x[k],sum-i);
      return false;
    }
  }

  cout<<"IMPOSSIBLE"<<endl;

  return true;
}


main(){
  cin>>n;
  
  FOR(i,2,n+1){
    int a;
    cin>>a;
    es[a].PB(i);
  }

  FOR(i,1,n+1){
    cin>>x[i];
  }

  RFOR(i,n,1){
    if(f(i)){
      return 0;
    }
  }

  cout<<"POSSIBLE"<<endl;
}
