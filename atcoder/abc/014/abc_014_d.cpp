
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

struct LCA{
  const int MAX_LOG_V = 50;

  vector<vector<int> > G,parent;
  int root=0,V;
  vector<int> depth;
  LCA(){}
  LCA(int V):V(V){init();}

  void init(){
    for(int i=0;i<(int)G.size();i++) G[i].clear();
    G.clear();
    for(int i=0;i<(int)parent.size();i++) parent[i].clear();
    parent.clear();
    depth.clear();
    G.resize(V);
    parent.resize(MAX_LOG_V,vector<int>(V));
    depth.resize(V);
  }

  void add(int u,int v){
    G[u].PB(v);
  }

  void dfs(int v,int p,int d){
    parent[0][v]=p;
    depth[v]=d;
    for(int i=0;i<(int)G[v].size();i++){
      if(G[v][i]!=p) dfs(G[v][i],v,d+1);
    }
  }

  void construct(){
    dfs(root,-1,0);
    for(int k=0;k+1<MAX_LOG_V;k++){
      for(int v=0;v<V;v++){
        if(parent[k][v]<0) parent[k+1][v]=-1;
        else parent[k+1][v]=parent[k][parent[k][v]];
      }
    }
  }

  int lca(int u,int v){
    if(depth[u]>depth[v]) swap(u,v);
    for(int k=0;k<MAX_LOG_V;k++){
      if((depth[v]-depth[u])>>k&1){
        v=parent[k][v];
      }
    }
    if(u==v) return u;
    for(int k=MAX_LOG_V-1;k>=0;k--){
      if(parent[k][u]!=parent[k][v]){
        u=parent[k][u];
        v=parent[k][v];
      }
    }
    return parent[0][u];
  }
};

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n;
  cin>>n;
  LCA lca(n);
  rep(i,n-1){
    int x,y;
    cin>>x>>y;
    x--;y--;
    lca.add(x,y);
    lca.add(y,x);
  }

  lca.construct();

  int q;
  cin>>q;
  
  while(q--){
    int a,b;
    cin>>a>>b;
    a--;b--;
    int c=lca.lca(a,b);
    //cout<<lca.depth[a]<<' '<<lca.depth[b]<<' '<<lca.depth[c]<<endl;
    cout<<lca.depth[a]+lca.depth[b]-2*lca.depth[c]+1<<endl;
  }


}
