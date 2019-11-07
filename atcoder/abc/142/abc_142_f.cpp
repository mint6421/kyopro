
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


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n,m;
  cin>>n>>m;
  UG es(n);
  rep(i,m){
    int a,b;
    cin>>a>>b;
    a--;b--;
    es[a].PB(b);
  }

  int ans=inf;
  vi res;
  rep(s,n){
    vi dist(n,-1);
    vi prev(n,-1);
    queue<int> q;
    q.push(s);
    dist[s]=0;
    while(!q.empty()){
      int v=q.front(); q.pop();
      for(int e:es[v]){
        if(dist[e]!=-1) continue;
        dist[e]=dist[v]+1;
        prev[e]=v;
        q.push(e);
      }
    }

    rep(t,n){
      if(t==s||dist[t]==-1) continue;
      for(int e:es[t]){
        if(e!=s) continue;
        vi tmp;
        tmp.PB(s);
        int cur=t;
        while(cur!=s){
          tmp.PB(cur);
          cur=prev[cur];
        }
        if(ans>tmp.size()){
          ans=tmp.size();
          res=tmp;
        }
      }
    }
  }

  if(ans==inf) cout<<-1<<endl;
  else{
    cout<<ans<<endl;
    rep(i,res.size()){
      cout<<res[i]+1<<endl;
    }
  }


}
