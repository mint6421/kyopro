
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

  int t;
  cin>>t;
  while(t--){
    int n,x;
    cin>>n>>x;
    vi a;
    int maxd=0;
    rep(i,n){
      int d,h;
      cin>>d>>h;
      a.PB(d-h);
      maxd=max(maxd,d);
    }
    sort(all(a));
    reverse(all(a));
    int ans=0;
    int res=x-maxd;
    if(res<=0){
      cout<<1<<endl;
      continue;
    }
    if(a[0]<=0){
      cout<<-1<<endl;
      continue;
    }
   
    cout<<1+(res+a[0]-1)/a[0]<<endl;
  }

}
