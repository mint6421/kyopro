
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
#define PP pair<int,P>
void init(){
  cin.tie(0);
  ios::sync_with_stdio(false);
}

int h,w;
char s[600][600];
int d[600][600][2];
int sx,sy,gx,gy;


main(){
  cin>>h>>w;
  rep(i,h){
    cin>>s[i];
    rep(j,w){
      d[i][j][0]=inf;
      d[i][j][1]=inf;
      if(s[i][j]=='S'){
        sx=j;sy=i;
      }if(s[i][j]=='G'){
        gx=j;gy=i;
      }
    }
  }

  d[sy][sx][0]=0;

  queue<PP> q;
  q.push(PP(0,P(sy,sx)));

  while(!q.empty()){
    int v=q.front().F;
    P p=q.front().S;
    q.pop();
    int a=2-v;
   
    //cout<<p.F<<' '<<p.S<<' '<<d[p.F][p.S][v]<<' '<<v<<endl;
    FOR(i,-a,a+1){
      FOR(j,-a,a+1){
        if(i==0||j==0) continue;
        if(v==0&&abs(i)==abs(j)) continue;
        int y=p.F+i,x=p.S+j;
        //cout<<i<<' '<<j<<endl;
        if(!(0<=x&&x<w&&0<=y&&y<h)) continue;
        int t=v;
        if(s[y][x]=='R') t=abs(t-1);
        if(d[p.F][p.S][v]+1<d[y][x][t]){
          d[y][x][t]=d[p.F][p.S][v]+1;
            q.push(PP(t,P(y,x)));
        }
      }
    }
  }

  int ans=min(d[gy][gx][0],d[gy][gx][1]);

  cout<<(ans==inf?-1:ans)<<endl;
}
