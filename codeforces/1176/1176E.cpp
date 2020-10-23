
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
  int t;
  cin>>t;
  while(t--){
    int n,m;
    cin>>n>>m;
    UG es(n+1);
    rep(i,m){
      int a,b;
      cin>>a>>b;
      es[a].PB(b);
      es[b].PB(a);
    }
    vector<int> c(n+1,0);
    queue<int> q;
    q.push(1);
    c[1]=1;
    while(!q.empty()){
      int x=q.front(); q.pop();
      int y=(c[x]==1)?-1:1;
      for(auto e:es[x]){
        if(c[e]==0){
          c[e]=y;
          q.push(e);
        }
      }
    }
    vector<int> a,b;
    FOR(i,1,n+1){
      if(c[i]==1) a.PB(i);
      else b.PB(i);
    }

    if(a.size()<=b.size()){
      cout<<a.size()<<endl;
      rep(i,a.size()){
        cout<<a[i]<<' ';
      }
      cout<<endl;
    }else{
      cout<<b.size()<<endl;
      rep(i,b.size()){
        cout<<b[i]<<' ';
      }
      cout<<endl;
    }
  }
}
