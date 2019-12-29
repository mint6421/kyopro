

#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX
#define INF LLONG_MAX
#define ll long long
#define ull unsigned long long
#define M (int)(1e9+7)
#define P pair<int,int>
#define FOR(i,m,n) for(int i=(int)m;i<(int)n;i++)
#define RFOR(i,m,n) for(int i=(int)m;i>=(int)n;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,n,0)
#define all(a) a.begin(),a.end()
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
int Madd(int x,int y) {return (x+y)%M;}
int Msub(int x,int y) {return (x-y+M)%M;}
int Mmul(int x,int y) {return (x*y)%M;}




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

  int n;
  cin>>n;
  vi d(n,0);
  rep(i,n){
    rep(j,n){
      int a;
      cin>>a;
      d[i]+=(a<<j);
    }
  }

  vi a(n);
  rep(i,n){
    cin>>a[i];
  }

  int ans=INF;
  rep(bit,(1<<n)){
    int s=0;
    int use=0;
    rep(i,n){
      if(bit&(1<<i)){
        s+=a[i];
        use+=(1<<i);
      }
    }

    bool flag=true;
    while(flag){
      flag=false;
      rep(i,n){
        if(!(use&(1<<i))){
          if((use&d[i])==d[i]){
            flag=true;
            use+=(1<<i);
          }
        }
      }
    }

    if(use==(1<<n)-1) ans=min(ans,s);
  }

  cout<<ans<<endl;

}
