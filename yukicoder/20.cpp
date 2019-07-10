
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


int n,v,ox,oy;
int a[300][300];


main(){
  cin>>n>>v>>ox>>oy;
  ox--;oy--;
  rep(i,n){
    rep(j,n){
      cin>>a[i][j];
    }
  }

  int d[300][300];
  rep(i,n){
    rep(j,n){
      d[i][j]=inf;
    }
  }
  d[0][0]=0;

  queue<P> q;
  q.push(P(0,0));

  while(!q.empty()){
    P p=q.front(); q.pop();
    rep(k,4){
      int y=p.F+vy[k],x=p.S+vx[k];
      if(!(0<=x&&x<n&&0<=y&&y<n)) continue;
      if(d[p.F][p.S]+a[y][x]<d[y][x]){
        d[y][x]=d[p.F][p.S]+a[y][x];
        q.push(P(y,x));
      }
    }
  }

  if(d[n-1][n-1]<v){
    cout<<"YES"<<endl;
  }else{
    if(ox<0&&oy<0){
      cout<<"NO"<<endl;
    }else{
      int s=v-d[oy][ox];
      s*=2;
      rep(i,n){
        rep(j,n){
          d[i][j]=inf;
        }
      }
      d[oy][ox]=0;
      q.push(P(oy,ox));

      while(!q.empty()){
        P p=q.front(); q.pop();
        rep(k,4){
          int y=p.F+vy[k],x=p.S+vx[k];
          if(!(0<=x&&x<n&&0<=y&&y<n)) continue;
          if(d[p.F][p.S]+a[y][x]<d[y][x]){
            d[y][x]=d[p.F][p.S]+a[y][x];
            q.push(P(y,x));
          }
        }
      }
      if(d[n-1][n-1]<s){
        cout<<"YES"<<endl;
      }else{
        cout<<"NO"<<endl;
      }

    }
  }
}
