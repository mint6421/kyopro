

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

void dfs(int k,int p,int t,UG &es,vector<bool> &b){
  
  b[k]=true;
  
  for(int x:es[k]){
    if(x==p||x==t||b[x]) continue;
    dfs(x,k,t,es,b);
  }

}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int q;
  cin>>q;
  while(q--){
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    a--;b--;
    UG es(n);
    rep(i,m){
      int x,y;
      cin>>x>>y;
      x--;y--;
      es[x].PB(y);
      es[y].PB(x);
    }
    vi res;
    vector<bool> ba(n,false);
    vector<bool> bb(n,false);
    
    dfs(a,-1,b,es,ba);
    dfs(b,-1,a,es,bb);
    int ca=-1,cb=-1;
    rep(i,n){
      if(ba[i]&&!bb[i]) ca++;
      if(!ba[i]&&bb[i]) cb++;
    }
    
    //cout<<ca<<' '<<cb<<endl;
    cout<<ca*cb<<endl;
    
  }


}
