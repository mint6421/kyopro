
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


char s[3100][3100];
int d[3100][3100];
int ans=0;

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int h,w;
  cin>>h>>w;

  rep(i,h){
    cin>>s[i];
  }

  queue<P> q;


  FOR(i,-1,h+1){
    FOR(j,-1,w+1){
      if(s[i][j]=='.'||!(0<=i&&i<h&&0<=j&&j<w)){
        FOR(x,-1,2){
          FOR(y,-1,2){
            if(!(0<=i+y&&i+y<h&&0<=j+x&&j+x<w)) continue;
            if(d[y+i][x+j]) continue;
            if(s[y+i][x+j]=='.') continue;
            d[y+i][x+j]=1;
            ans=1;
            q.push(P(y+i,x+j));
          }
        }
      }
    }
  }
  //cout<<q.size()<<endl;

  while(!q.empty()){
    P p=q.front(); q.pop();
    FOR(i,-1,2){
      FOR(j,-1,2){
        int y=i+p.F,x=j+p.S;
        if(!(0<=x&&x<w&&0<=y&&y<h)) continue;
        if(d[y][x]) continue;
        if(s[y][x]=='.') continue;
        d[y][x]=d[p.F][p.S]+1;
        ans=max(ans,d[y][x]);
        q.push(P(y,x));
      }
    }
  }

  
  /*
  rep(i,h){
    rep(j,w){
      cout<<d[i][j]<<' ';
    }
    cout<<endl;
  }
  */

  cout<<ans<<endl;


}
