
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
#define PP pair<P,int>



signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  vector<PP> v;
  cin>>n;
  rep(i,n){
    vi a(3);
    cin>>a[0]>>a[1]>>a[2];
    sort(all(a));
    v.PB(PP(P(a[0],a[1]),a[2]));
  }
  sort(all(v));

  vi d(n,1);

  rep(i,n){
    FOR(j,i+1,n){
      if(v[i].F.F<v[j].F.F&&v[i].F.S<v[j].F.S&&v[i].S<v[j].S)
        d[j]=max(d[j],d[i]+1);
    }
  }

  int ans=0;
  rep(i,n){
    ans=max(ans,d[i]);
  }

  cout<<ans<<endl;

}
