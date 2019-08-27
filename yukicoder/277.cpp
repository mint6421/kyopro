
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
UG es;
int r[110000];
int l[110000];
queue<P> q;

void dfs(int k,int p,int s){
  r[k]=s;

  for(auto e:es[k]){
    if(e==p) continue;
    dfs(e,k,s+1);
  }
  if(es[k].size()==1) q.push(P(k,0));
}


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin>>n;
  es=UG(n);
  rep(i,n-1){
    int a,b;
    cin>>a>>b;
    a--;b--;
    es[a].PB(b);
    es[b].PB(a);
  }


  dfs(0,-1,0);

  rep(i,n){
    l[i]=-1;
  }

  while(!q.empty()){
    P p=q.front(); q.pop();
    if(l[p.F]!=-1) continue;
    l[p.F]=p.S;
    for(auto e:es[p.F]){
      q.push(P(e,p.S+1));
    }
  }

  rep(i,n){
    cout<<min(r[i],l[i])<<endl;
  }
      


}
