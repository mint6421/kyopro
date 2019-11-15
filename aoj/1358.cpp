
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

  int n,m;
  cin>>n>>m;
  int a,b,c;
  cin>>a>>b>>c;

  WG<int> esa(n*a),esb(n*b),esc(n*c);

  rep(i,m){
    int x,y;
    cin>>x>>y;
    x--;y--;
    rep(k,a){
      esa[n*k+y].PB(edge<int>((n*(k+1))%(n*a)+x,1));
    }
    rep(k,b){
      esb[n*k+y].PB(edge<int>((n*(k+1))%(n*b)+x,1));
    }
    rep(k,c){
      esc[n*k+y].PB(edge<int>((n*(k+1))%(n*c)+x,1));
    }
  }
  

  vi dist(n,inf);
  dist[n-1]=0;
  queue<int> q;
  q.push(n-1);

  int distabc[100][3]={};
  rep(i,n){
    rep(j,3){
      distabc[i][j]=inf;
    }
  }


  while(q.size()){
    int x=q.front(); q.pop();
    vi da=dijkstra(esa,x);
    vi db=dijkstra(esb,x);
    vi dc=dijkstra(esc,x);
    rep(i,n){
      //cout<<da[i]<<' '<<db[i]<<' '<<dc[i]<<endl;
      if(da[i]/a==1){
        distabc[i][0]=dist[x]+1;
      }
      if(db[i]/b==1){
        distabc[i][1]=dist[x]+1;
      }
      if(dc[i]/c==1){
        distabc[i][2]=dist[x]+1;
      }
      if(dist[i]==inf&&distabc[i][0]<inf&&distabc[i][1]<inf&&distabc[i][2]<inf){
        dist[i]=max(distabc[i][0],max(distabc[i][1],distabc[i][2]));
        q.push(i);
      }
   }
  }


  rep(i,n){
    //cout<<dist[i]<<endl;
  } 

  if(dist[0]==inf){
    cout<<"IMPOSSIBLE"<<endl;
  }else{
    cout<<dist[0]<<endl;
  }
  
}
