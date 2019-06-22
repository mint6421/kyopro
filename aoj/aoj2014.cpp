
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


void f(int w,int h){

  char s[100][100];
  rep(i,h){
    cin>>s[i];
  }

  bool sw[100][100]={},sb[100][100]={};

  queue<P> q;
  rep(i,h){
    rep(j,w){
      if(s[i][j]=='W') q.push(P(i,j));
    }
  }

  while(!q.empty()){
    P p=q.front(); q.pop();
    rep(k,4){
      int x=p.S+vx[k];
      int y=p.F+vy[k];
      if(!(0<=x&&x<w&&0<=y&&y<h)) continue;
      if(s[y][x]!='.') continue;
      if(!sw[y][x]){
        sw[y][x]=true;
        q.push(P(y,x));
      }
    }
  }


  rep(i,h){
    rep(j,w){
      if(s[i][j]=='B') q.push(P(i,j));
    }
  }

  while(!q.empty()){
    P p=q.front(); q.pop();
    rep(k,4){
      int x=p.S+vx[k];
      int y=p.F+vy[k];
      if(!(0<=x&&x<w&&0<=y&&y<h)) continue;
      if(s[y][x]!='.') continue;
      if(!sb[y][x]){
        sb[y][x]=true;
        q.push(P(y,x));
      }
    }
  }


  int nb=0,nw=0;
  rep(i,h){
    rep(j,w){
      if(s[i][j]!='.') continue;
      if(!(sb[i][j]^sw[i][j])) continue;
      if(sb[i][j]) nb++;
      else nw++;
    }
  }

  cout<<nb<<' '<<nw<<endl;


}



      
main(){
  int h,w;
  while(true){
    cin>>w>>h;
    if(w==0) break;
    f(w,h);
  }
}
