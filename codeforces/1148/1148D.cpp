
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
#define PP pair<P,int>
void init(){
  cin.tie(0);
  ios::sync_with_stdio(false);
}


main(){
  int n;
  cin>>n;
  vector<PP> a,b;
  rep(i,n){
    int x,y;
    cin>>x>>y;
    if(x<y){
      a.PB(PP(P(y,x),i+1));
    }else{
      b.PB(PP(P(x,y),i+1));
    }
  }

  sort(all(a));
  sort(all(b));
  reverse(all(a));

  vector<int> va,vb;
  int na;
  if(a.size()){
    va.PB(a[0].S);
    na=a[0].F.F;
  }

  FOR(i,1,a.size()){
    if(a[i].F.S<na){
      va.PB(a[i].S);
      na=a[i].F.F;
    }
  }

  int nb;
  if(b.size()){
    vb.PB(b[0].S);
    nb=b[0].F.S;
  }

  FOR(i,1,b.size()){
    //cout<<nb<<' '<<b[i].F.F<<endl;
    if(b[i].F.F>nb){
      vb.PB(b[i].S);
      nb=b[i].F.S;
    }
  }

  if(va.size()>vb.size()){
    cout<<va.size()<<endl;
    rep(i,va.size()){
      cout<<va[i]<<' ';
    }
    cout<<endl;
  }else{
    cout<<vb.size()<<endl;
    rep(i,vb.size()){
      cout<<vb[i]<<' ';
    }
    cout<<endl;
  }
}
