
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

void f(int n,int m){
  int sx,sy;
  int dd=150;

  int d[300][300];
  rep(i,300){
    rep(j,300){
      d[i][j]=INF;
    }
  }

  d[dd][dd]=0;
  vector<P> v;

  while(m--){
    int x,y;
    cin>>x>>y;
    v.PB(P(x,y));
  }
  
  cin>>sx>>sy;

  rep(i,v.size()){
    d[v[i].S+dd-sy][v[i].F+dd-sx]=-INF;
  }
  

  queue<P> q;
  q.push(P(dd,dd));
  int ans=0;
  while(!q.empty()){
    P p=q.front(); q.pop();
    if(d[p.F][p.S]<=n)
      ans++;
    else
      continue;
    //cout<<p.F<<' '<<p.S<<endl;
    if(abs(p.F-dd)>31||abs(p.S-dd)>31) continue;
    FOR(i,-1,2){
      FOR(j,-1,2){
        if(i==0&&j==0||i*j<0) continue;
        int x=p.S+i,y=p.F+j;
        if(d[y][x]>d[p.F][p.S]+1){
          d[y][x]=d[p.F][p.S]+1;
          q.push(P(y,x));
        }
      }
    }
  }

  cout<<ans<<endl;
}




main(){
  int n,m;
  while(true){
    cin>>n>>m;
    if(n==0) break;
    f(n,m);
  }

}
