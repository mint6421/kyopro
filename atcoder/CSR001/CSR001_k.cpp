
#include<bits/stdc++.h>
using namespace std;
#define inf 1000000000
#define INF 1000000000000000
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
void init(){
  cin.tie(0);
  ios::sync_with_stdio(false);
}


main(){
  int n;
  cin>>n;
  int a[110000];
  rep(i,n){
    cin>>a[i];
  }
  int v[110000];
  v[n-1]=1;
  rrep(i,n-2){
    v[i]=((n-i)*v[i+1])%M;
  }

  vector<int> s;
  FOR(i,1,n+1){
    s.PB(i);
  }

  int ans=1;
  rep(i,n){
    auto m=lower_bound(all(s),a[i]);
    
//    cout<<v[i+1]<<' '<<a[i]<<' '<<ans<<endl;
    ans+=(m-s.begin())*v[i+1];
    ans%=M;
    s.erase(m);
  }

  cout<<ans<<endl;
}
