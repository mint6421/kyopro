
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
  

  int n;
  cin>>n;
  vi a(n);
  rep(i,n){
    cin>>a[i];
  }
  vector<P> b;
  rep(i,n){
    b.PB(P(a[i],i));
  }
  sort(all(b));

  set<P> sr,sl;
  int ans=0;
  rep(i,n){
    auto itr=sr.lower_bound(P(b[i].S,b[i].F));
    auto itl=sl.lower_bound(P(-b[i].S,b[i].F));
    int r,l;
    if(itr==sr.end()) r=n;
    else r=itr->F;
    if(itl==sl.end())
      l=-1;
    else l=-itl->F;
    //cout<<l<<' '<<r<<endl;
    ans+=b[i].F*(b[i].S-l)*(r-b[i].S);
    //cout<<ans<<endl;

    //cout<<r<<' '<<l<<endl;
    sr.insert(P(b[i].S,b[i].F));
    sl.insert(P(-b[i].S,b[i].F));
  }

  cout<<ans<<endl;

}
