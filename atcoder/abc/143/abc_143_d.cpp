
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
#define Yes(f){cout<<(f?"Yes":"No")<<endl;}
#define YES(f){cout<<(f?"YES":"NO")<<endl;}


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n;
  cin>>n;
  vi v(n);
  
  rep(i,n){
    cin>>v[i];
  } 
 
  sort(all(v));
  v.PB(inf);


  int ans=0;

  rep(i,n){
    FOR(j,i+1,n){
      int l=upper_bound(all(v),v[j]-v[i])-v.begin();
      int r=lower_bound(all(v),v[i]+v[j])-v.begin();
      
      //cout<<' '<<v[i]<<' '<<v[j]<<endl;
      int res=r-l;
      //cout<<res<<endl;
      if(v[l]<=v[i]&&v[i]<=v[r]) res--;
      if(v[l]<=v[j]&&v[j]<=v[r]) res--;

      //cout<<r<<' '<<l<<endl;
      ans+=max(res,0LL);
    }
  }
  cout<<ans/3<<endl;


}
