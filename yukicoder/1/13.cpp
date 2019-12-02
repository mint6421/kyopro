
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

int w,h;
int a[110][110];
bool b[110][110];

bool dfs(int i,int j,int pi,int pj){
  b[i][j]=true;
  //cout<<i<<' '<<j<<' '<<pi<<' '<<pj<<endl;
  bool flag=false;
  rep(k,4){
    int y=i+vy[k],x=j+vx[k];
    if(y==pi&&x==pj) continue;
    if(!(0<=x&&x<w&&0<=y&&y<h)) continue;
    if(a[i][j]==a[y][x]){
      if(b[y][x]){

        return true;
      }
      flag|=dfs(y,x,i,j);
    }
  }

  return flag;
}



main(){
  cin>>w>>h;
  rep(i,h){
    rep(j,w){
      cin>>a[i][j];
    }
  }

  rep(i,h){
    rep(j,w){
      if(b[i][j]) continue; 
      if(dfs(i,j,-1,-1)){
        cout<<"possible"<<endl;
        return 0;
      }
    }
  }

  cout<<"impossible"<<endl;
}

