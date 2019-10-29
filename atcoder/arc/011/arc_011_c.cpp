
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
#define IP pair<int,P>
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



template< typename T >
vector<T> dijkstra(WG<T> &g,int s){
  const auto lim = numeric_limits<T>::max();
  vector<T> dist(g.size(),lim);
  using Pi = pair<T,int>;
  priority_queue<Pi,vector<Pi>,greater<Pi>> q;
  dist[s] = 0;
  q.emplace(dist[s],s);
  while(!q.empty()){
    T cost;
    int idx;
    tie(cost,idx) = q.top();
    q.pop();
    if(dist[idx] < cost) continue;
    for( auto &e : g[idx]){
      auto next_cost = cost + e.cost;
      if(dist[e.to] <= next_cost) continue;
      dist[e.to] = next_cost;
      q.emplace(dist[e.to],e.to);
    }
  }
  return dist;
}


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  string s,t;
  cin>>s>>t;
  int n;
  cin>>n;
  vector<string> v;
  v.PB(s);
  rep(i,n){
    string u;
    cin>>u;
    v.PB(u);
  }
  v.PB(t);

  WG<int> es(n+2);

  rep(i,n+2){
    FOR(j,i+1,n+2){
      string s,t;
      //cout<<i<<' '<<j<<endl;
      s=v[i];
      t=v[j];
      //cout<<s<<' '<<t<<endl;
      int diff=0;
      rep(l,s.size()){
        diff+=(s[l]!=t[l]);
      }
      if(diff==1){
        es[i].PB(edge<int>(j,1));
        es[j].PB(edge<int>(i,1));
      }
    }
  }

  vector<vi> res;
  rep(i,n+2){
    res.PB(dijkstra(es,i));
  }

  if(res[0][n+1]==INF){
    cout<<-1<<endl;
  }else if(v[0]==v[n+1]){
    cout<<0<<endl;
    cout<<v[0]<<endl;
    cout<<v[0]<<endl;
  }else{
    cout<<res[0][n+1]-1<<endl;
    int s=0;
    while(s!=n+1){
      cout<<v[s]<<endl;
      rep(i,n+2){
        if(i==s) continue;
        if(res[s][i]!=INF&&res[i][n+1]!=INF&&res[s][i]==1&&res[s][i]+res[i][n+1]==res[s][n+1]){
          s=i;
          break;
        }
      }
    }
    cout<<v[s]<<endl;
  }

  


}
