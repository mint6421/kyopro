
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

int n,m;
vector<IP> a;

int f(int x,int y,int z){

  vi v(n);

  rep(i,n){
    v[i]=a[i].F*x+a[i].S.F*y+a[i].S.S*z;
  }

  sort(all(v));
  reverse(all(v));

  int res=0;
  rep(i,m){
    res+=v[i];
  }
  return res;
}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  cin>>n>>m;
  a=vector<IP>(n);
  rep(i,n){
    cin>>a[i].F>>a[i].S.F>>a[i].S.S;
  }

  int ans=-INF;

  FOR(i,-1,2){
    FOR(j,-1,2){
      FOR(k,-1,2){
        if(i==0||j==0||k==0) continue;
        ans=max(ans,f(i,j,k));
      }
    }
  }


  cout<<ans<<endl;


}
