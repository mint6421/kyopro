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
//#define int ll
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



class ErdosNumber{
  public:
    vector<string> calculateNumbers(vector<string> publications){

      map<string,int> mp;
      int n=0;

      for(string s:publications){
        int i=0;
        while(i<s.size()){
          int j=i;
          string t;
          while(j<s.size()&&s[j]!=' '){
            t+=s[j];
            j++;
          }
          if(mp.find(t)==mp.end()){
            mp[t]=n;
            n++;
          }
          i=j+1;
        }
      }

      WG<int> es(n);
      for(string s:publications){
        int i=0;
        vector<string> res;
        while(i<s.size()){
          int j=i;
          string t;
          while(j<s.size()&&s[j]!=' '){
            t+=s[j];
            j++;
          }
          res.PB(t);
          i=j+1;
        }
        rep(i,res.size()){
          FOR(j,i+1,res.size()){
            es[mp[res[i]]].PB(edge<int>(mp[res[j]],1));
            es[mp[res[j]]].PB(edge<int>(mp[res[i]],1));
          }
        }
      }

      vi dist=dijkstra(es,mp["ERDOS"]);
      vector<string> ans;
      for(auto p:mp){
        if(dist[p.S]==inf)
          ans.PB(p.F);
        else
          ans.PB(p.F+' '+to_string(dist[p.S]));
      }

      sort(all(ans));

      return ans;


    }
};
