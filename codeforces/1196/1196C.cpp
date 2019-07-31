
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



signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int q;
  cin>>q;
  while(q--){
    int n;
    cin>>n;

    int minx=-100000,maxy=100000,maxx=100000,miny=-100000;

    rep(i,n){
      int x,y,a,b,c,d;
      cin>>x>>y>>a>>b>>c>>d;
      if(!a) minx=max(minx,x);
      if(!b) maxy=min(maxy,y);
      if(!c) maxx=min(maxx,x);
      if(!d) miny=max(miny,y);
    }

    if(minx<=maxx&&miny<=maxy){
      cout<<1<<' '<<minx<<' '<<miny<<endl;
    }else{
      cout<<0<<endl;
    }
  }


}
