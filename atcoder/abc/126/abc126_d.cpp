
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


WG<int> es;

void dfs(int x,int r,int b[],int c){

  for(auto e:es[x]){
//    cout<<e.to<<endl;
    if(e.to==r||b[e.to]!=-1) continue;
//    cout<<e.to<<' '<<c<<' '<<e.cost<<endl;
    if((c+e.cost)%2){
      b[e.to]=0;
    }else{
      b[e.to]=1;
    }
    dfs(e.to,x,b,c+e.cost);
  }
 
}


main(){
  int n;
  cin>>n;
  es.resize(n);
  int b[110000]={};

  rep(i,n-1){
    int a,b,c;
    cin>>a>>b>>c;
    a--;
    b--;
    es[a].PB(edge<int>(b,c%2));
    es[b].PB(edge<int>(a,c%2));
  }

  rep(i,n){
    b[i]=-1;
  }

  b[0]=1; 

  dfs(0,-1,b,0);


  rep(i,n){
    cout<<b[i]<<endl;
  }
}
