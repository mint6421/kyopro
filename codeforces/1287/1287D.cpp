

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

int n;
int c[2100],p[2100];
vector<vi> es(2100);
vector<vi> s(2100);


void dfs(int x){
  p[x]=1;
  for(int i:es[x]){
    dfs(i);
    p[x]+=p[i];
    for(int k:s[i]){
      s[x].PB(k);
    }
  }

  if(p[x]<=c[x]){
    cout<<"NO"<<endl;
    exit(0);
  }
  s[x].insert(s[x].begin()+c[x],x);
}


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  cin>>n;
  int root;
  FOR(i,1,n+1){
    int p;
    cin>>p>>c[i];
    es[p].PB(i);
    if(p==0) root=i;
  }

  dfs(root);

  cout<<"YES"<<endl;
  int cnt=1;
  vi ans(n+1);
  for(int x:s[root]){
    ans[x]=cnt++;
  }

  FOR(i,1,n+1){
    cout<<ans[i]<<' ';
  }
  cout<<endl;


}
