
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
#define IP pair<int,P>
#define PP pair<P,P>


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int a,b,c,d,n;
  cin>>a>>b>>c>>d>>n;

  int m=a*(c-1)+b*(d-1);

  cout<<max(0LL,n-m)<<' ';

  int ans1,ans2;
  int n1=c*min(a,n/c);
  ans1=n1/c+min(b,(n-n1)/d);
  int n2=d*min(b,n/d);
  ans2=n2/d+min(a,(n-n2)/c);

  //cout<<ans1<<' '<<ans2<<endl;

  cout<<max(ans1,ans2)<<endl;

}
