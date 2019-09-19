
#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX
#define INF LLONG_MAX
//#define ll long long
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
#define int long long
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
  reverse(all(b));

  set<P> sr,sl;
  int ans=0;
  rep(i,n){
    auto itr=sr.lower_bound(P(b[i].S,b[i].F));
    auto itl=sl.lower_bound(P(-b[i].S,b[i].F));
    auto itrr=sr.upper_bound(P(*itr));
    auto itll=sl.upper_bound(P(*itl));
    int r,l,rr,ll;
    if(itr==sr.end()) r=n;
    else r=itr->F;
    if(itrr==sr.end()) rr=n;
    else rr=itrr->F;

    if(itl==sl.end())
      l=-1;
    else l=-itl->F;
    if(itll==sl.end())
      ll=-1;
    else ll=-itll->F;

    //cout<<l<<' '<<r<<endl;
    if(r!=n)
      ans+=b[i].F*(b[i].S-l)*(rr-r);
    //cout<<' '<<ans<<endl;
    if(l!=-1)
      ans+=b[i].F*(r-b[i].S)*(l-ll);
    //cout<<rr<<' '<<r<<' '<<ll<<' '<<l<<endl;
    //cout<<(b[i].S-l)<<' '<<(r-b[i].S)<<endl;
    //cout<<ans<<endl;

    //cout<<r<<' '<<l<<endl;
    sr.insert(P(b[i].S,b[i].F));
    sl.insert(P(-b[i].S,b[i].F));
  }

  cout<<ans<<endl;

}
