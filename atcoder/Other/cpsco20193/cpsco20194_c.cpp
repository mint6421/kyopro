
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


int n,d;

main(){
  cin>>n>>d;
  vector<int> v(n);

  rep(i,n){
    cin>>v[i];
  }

  sort(all(v));
  v.PB(INF);
/*
  rep(i,n+1){
    cout<<v[i]<<' '<<v[i]+d<<endl;
  }
*/
  int ans=0;
  rep(i,n){
    auto itr =lower_bound(all(v),v[i]+d+1);
//    cout<<" "<<itr-v.begin()<<endl;
    if(itr>v.begin()+i+2){
      int res=itr-v.begin()-i;
      ans+=(res-1)*(res-2)/2;
    }

 //   cout<<ans<<endl;
  }

  cout<<ans<<endl;
}
