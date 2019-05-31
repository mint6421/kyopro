
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

P v[210000];
set<int> s;
int res;
UG es;

void dfs(int k,bool b[]){
  //cout<<' '<<k<<endl;
  if(b[k]) return;
  res++;
  b[k]=true;
  s.insert(v[k].F);
  s.insert(v[k].S);
  
  for(int e:es[k]){
    dfs(e,b);
  }
}


main(){
  int n;
  cin>>n;
  map<int,int> mp;
  es.resize(n+1);

  FOR(i,1,n+1){
    int a,b;
    cin>>a>>b;
    v[i]=P(a,b);

    if(mp[a]){
      es[mp[a]].PB(i);
      es[i].PB(mp[a]);
    }else{
      mp[a]=i;
    }

    if(mp[b]&&a!=b){
      es[mp[b]].PB(i);
      es[i].PB(mp[b]);
    }else{
      mp[b]=i;
    }
  }

  int ans=0;
  bool b[300000]={};
  FOR(i,1,n+1){
    s.clear();
    res=0;
    dfs(i,b);
    ans+=min((int)s.size(),res);
    //cout<<ans<<endl;
  }


  cout<<ans<<endl;

}
