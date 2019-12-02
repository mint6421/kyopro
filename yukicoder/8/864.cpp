
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

  int n,k;
  cin>>n>>k;

  int ans=0;
  for(int i=2;i*i<=k;i++){
    if(k%i) continue;
    int j=k/i;
    //cout<<i<<' '<<j<<endl;
    int a,b;
    if(2<=i&&i<=n+1) a=i-1;
    else if(n+2<=i&&i<=2*n) a=2*n+1-i;
    else a=0;

    if(2<=j&&j<=n+1) b=j-1;
    else if(n+2<=j&&j<=2*n) b=2*n+1-j;
    else b=0;

    //cout<<a<<"  "<<b<<endl;

    ans+=(1+(i!=j))*a*b;
  }

  cout<<ans<<endl;

}
