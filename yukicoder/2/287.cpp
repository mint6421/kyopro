
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
  int ans=0;
  rep(a,2*n+1){
    rep(b,2*n+1){
      rep(c,2*n+1){
        int d=6*n-(a+b+c);
        if(d>2*n) continue;
        int i=min(2*n-a+1,a+1);
        int j=min(2*n-b+1,b+1);
        int k=min(2*n-c+1,c+1);
        int l=min(2*n-d+1,d+1);
        //cout<<i<<' '<<j<<' '<<k<<' '<<l<<endl;
        ans+=i*j*k*l;
      }
    }
  }

  cout<<ans<<endl;


}
