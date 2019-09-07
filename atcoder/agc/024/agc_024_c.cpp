
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
  reverse(all(a));

  int ans=0;
  rep(i,n){
    //cout<<a[i]<<' '<<a[i+1]<<' '<<ans<<endl;
    if(i==n-1){
      if(a[i]!=0){
        ans=-1;
        break;
      }
    }else{
      if(a[i]==1||a[i]-a[i+1]==1){
        ans++;
      }else if(a[i]<=a[i+1]){
        ans+=a[i];
      }else{
        ans=-1;
        break;
      }
    }
  }

  cout<<ans<<endl;

}
