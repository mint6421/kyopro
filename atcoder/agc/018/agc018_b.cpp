
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


int ans=inf;
bool b[400];
int n,m;
int a[400][400];

void f(){
 
  map<int,int> mp;

  rep(i,n){
    rep(j,m){
      if(!b[a[i][j]]) continue;
      mp[a[i][j]]++;
      break;
    }
  }
  int ret=-1,res=-1;

  for(auto s :mp){
    if(s.S>ret){
      ret=s.S;
      res=s.F;
    }
  }
  
//  cout<<ret<<' '<<res<<endl;
  if(ret==-1) return;

  ans=min(ans,ret);
  b[res]=false;
  f();
}



main(){
  cin>>n>>m;
  rep(i,n){
    rep(j,m){
      cin>>a[i][j];
    }
  }

  rep(i,m+1){
    b[i]=true;
  }

  f();

  cout<<ans<<endl;
}
