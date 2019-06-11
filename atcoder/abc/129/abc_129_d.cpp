
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


int h,w;
char s[2100][2100];
int a[2100][2100],b[2100][2100],c[2100][2100],d[2100][2100];

main(){
  cin>>h>>w;
  rep(i,h){
    cin>>s[i];
  }

  rep(i,h){
    int t=-1;
    rep(j,w){
      if(s[i][j]=='#'){
        t=-1;
      }else{
        t++;
      }
      a[i][j]=t;
    }
  }

  rep(i,h){
    int t=-1;
    rrep(j,w-1){
      if(s[i][j]=='#'){
        t=-1;
      }else{
        t++;
      }
      b[i][j]=t;
    }
  }

  rep(j,w){
    int t=-1;
    rep(i,h){
      if(s[i][j]=='#'){
        t=-1;
      }else{
        t++;
      }
      c[i][j]=t;
    }
  }

  rep(j,w){
    int t=-1;
    rrep(i,h-1){
      if(s[i][j]=='#'){
        t=-1;
      }else{
        t++;
      }
      d[i][j]=t;
    }
  }

  int ans=0;
  rep(i,h){
    rep(j,w){
      if(s[i][j]=='#') continue;
      ans=max(ans,a[i][j]+b[i][j]+c[i][j]+d[i][j]+1);
    }
  }

  cout<<ans<<endl;
}
