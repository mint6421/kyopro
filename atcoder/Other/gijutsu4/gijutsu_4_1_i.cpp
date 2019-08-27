
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

  int n,m;
  cin>>n>>m;
  vi a(n),b(m);
  rep(i,n){
    cin>>a[i];
  }
  rep(i,m){
    cin>>b[i];
  }
  sort(all(a));
  sort(all(b));

  int ans=0,t=0;
  rrep(i,n-1){
    int l=lower_bound(all(b),a[i])-b.begin();
    ans+=(l*t)%M;
    ans%=M;
    //cout<<ans<<' '<<a[i]<<' '<<l<<' '<<t<<endl;
    int r=upper_bound(all(b),a[i])-b.begin();
    t+=m-r;
    t%=M;
  }

  cout<<ans<<endl;

}
