
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


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n,m;
  cin>>n>>m;
  int d[410][410];
  rep(i,n){
    rep(j,n){
      if(i==j) d[i][j]=0;
      d[i][j]=INF;
    }
  }

  rep(i,m){
    int a,b,c;
    cin>>a>>b>>c;
    a--;b--;
    d[a][b]=min(d[a][b],c);
    d[b][a]=min(d[b][a],c);
  }

  rep(k,n){
    rep(i,n){
      rep(j,n){
        if(i==j||j==k||k==i) continue;
        if(d[i][k]==INF||d[k][j]==INF) continue;
        d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
      }
    }
  }
  //cout<<ans<<endl;

  int q;
  cin>>q;
  while(q--){
    int x,y,z;
    cin>>x>>y>>z;
    x--;y--;
    d[x][y]=min(d[x][y],z);
    d[y][x]=min(d[y][x],z);

    
    rep(i,n){    
      if(i==x||i==y) continue;
        d[i][x]=min(d[i][x],d[i][y]+z);
        d[i][y]=min(d[i][y],d[i][x]+z);
        d[x][i]=min(d[x][i],d[y][i]+z);
        d[y][i]=min(d[y][i],d[x][i]+z);
    }
    
    rep(i,n){
      rep(j,n){        
        if(i==j) continue;
        if(i!=x&&j!=y)d[i][j]=min(d[i][j],d[i][x]+d[y][j]+z);
        if(i!=y&&j!=x)d[i][j]=min(d[i][j],d[i][y]+d[x][j]+z);
      }
    }

    int ans=0;
    rep(i,n){
      rep(j,n){
        if(i==j) continue;
        ans+=d[i][j];
      }
    }

    cout<<ans/2<<endl;
  }



}
