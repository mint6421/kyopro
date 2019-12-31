
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


int dfs(int i,int p,vector<bool> &b,UG &es){
  
  int res=1;
  b[i]=true;

  for(int e:es[i]){
    if(b[e]||e==p) continue;
    res+=dfs(e,i,b,es);
  }

  return res;
}


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n;
  cin>>n;
  vector<P> a;
  vector<P> v;
  rep(i,n){
    int x,y;
    cin>>x>>y;
    a.PB(P(x,y));
    v.PB(P(x,i));
    v.PB(P(y,i));
  }

  sort(all(v));

  int cnt=0;
  set<P> st;
  UG es(n);

  for(P p:v){
    if(cnt>=n) break;
    if(st.find(p)!=st.end()){
      st.erase(p);
    }else{
      int i=p.S;
      int r=a[i].S;
      for(P jt:st){
        if(jt.F>r) break;
        int j=jt.S;
        es[i].PB(j);
        es[j].PB(i);
        cnt++;
        if(cnt>=n) break;
      }
      st.insert(P(a[i].S,i));
    }
  }

  vector<bool> b(n,false);
  YES(cnt==n-1&&dfs(0,-1,b,es)==n);



}
