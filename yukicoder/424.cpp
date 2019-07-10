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


main(){
  int h,w,sx,sy,gx,gy;
  cin>>h>>w;
  cin>>sy>>sx>>gy>>gx;
  int d[100][100];
  bool b[100][100]={};
  rep(i,h){
    string s;
    cin>>s;
    rep(j,w){
      d[i][j]=s[j]-'0';
    }
  }

  sx--;sy--;gx--;gy--;

  queue<P> q;
  q.push(P(sy,sx));
  
  int wx[4]={2,0,-2,0};
  int wy[4]={0,2,0,-2};
  b[sy][sx]=true;

  while(!q.empty()){
    P p=q.front(); q.pop();
    //cout<<p.F<<' '<<p.S<<endl;
    rep(k,4){
      int x=p.S+vx[k],y=p.F+vy[k];
      //cout<<x<<' '<<y<<' '<<w<<' '<<x<<endl;
      if(!(0<=x&&x<w&&0<=y&&y<h)) continue;
      //cout<<d[p.F][p.S]<<' '<<d[y][x]<<endl;
      if(abs(d[p.F][p.S]-d[y][x])<2&&!b[y][x]){
        b[y][x]=true;
        q.push(P(y,x));
      }
    }

    rep(k,4){
      int x=p.S+wx[k],y=p.F+wy[k];
      if(!(0<=x&&x<w&&0<=y&&y<h)) continue;
      if(abs(d[p.F][p.S]-d[y][x])==0&&d[(p.F+y)/2][(p.S+x)/2]<d[y][x]&&!b[y][x]){
        b[y][x]=true;
        q.push(P(y,x));
      }
    }

  }

  if(b[gy][gx]){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }

}


