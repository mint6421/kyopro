
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
void init(){
  cin.tie(0);
  ios::sync_with_stdio(false);
}


int main(){
  int h,w;
  char s[1100][1100];
  queue<P> q;

  cin>>h>>w;



  int a[1100][1100];
  rep(i,h){
    rep(j,w){
      a[i][j]=inf;
    }
  }

  rep(i,h){
    cin>>s[i];
    rep(j,w){
      if(s[i][j]=='#'){
        a[i][j]=0;
        q.push(P(i,j));
      }
    }
  }


  while(!q.empty()){
    P p=q.front(); q.pop();
    rep(k,4){
      int x=p.S+vx[k],y=p.F+vy[k];
      if(!(0<=x&&x<w&&0<=y&&y<h)) continue;
      if(a[y][x]>a[p.F][p.S]+1){
        a[y][x]=a[p.F][p.S]+1;
        q.push(P(y,x));
      }
    }
  }

  int ans=-1;
  rep(i,h){
    rep(j,w){
      ans=max(ans,a[i][j]);
    }
  }

  cout<<ans<<endl;
}
