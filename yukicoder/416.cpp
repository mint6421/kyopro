
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
//#define int ll
#define vi vector<int>



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


UG es;
int ans[210000];
set<P> s;
vector<P> v;

void dfs(int k,int p,int x){
  ans[k]=x;
  for(int e:es[k]){
    if(e==p||ans[e]) continue;
    dfs(e,k,x);
  }

}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n,m,q;
  cin>>n>>m>>q;
  rep(i,m){
    int a,b;
    cin>>a>>b;
    a--;b--;
    s.insert(P(a,b));
  }

  v = vector<P>(q);
  rep(i,q){
    cin>>v[i].F>>v[i].S;
    v[i].F--;v[i].S--;
    s.erase(P(v[i]));
  }

  es=UG(n);

  for(P p:s){
    es[p.F].PB(p.S);
    es[p.S].PB(p.F);
  }


  dfs(0,-1,-1);


  rrep(i,q-1){
    //cout<<i<<endl;
    //cout<<v[i].F<<' '<<v[i].S<<endl;
    if(ans[v[i].F]&&!ans[v[i].S]){
      
      dfs(v[i].S,-1,i+1);
    }else if(!ans[v[i].F]&&ans[v[i].S]){
      dfs(v[i].F,-1,i+1);
    }
    
    es[v[i].F].PB(v[i].S);
    es[v[i].S].PB(v[i].F);
    //rep(i,n) cout<<ans[i]<<' ';
    //cout<<endl;
  }

  FOR(i,1,n){
    cout<<ans[i]<<endl;
  }

  
}
