
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
#define F first
#define S second
#define PB push_back
#define EB emplace_back
#define int ull
#define vi vector<int>
#define IP pair<int,P>
#define PI pair<P,int>
#define PP pair<P,P>
#define Yes(f){cout<<(f?"Yes":"No")<<endl;}
#define YES(f){cout<<(f?"YES":"NO")<<endl;}



ll power(ll x,ll k){
  ll ret=1;
  while(k>0){
    if(k&1) (ret*=x) %= M;
    (x*=x) %= M;
    k >>= 1;
  }
  return ret;
}


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n;
  cin>>n;
  vi a(n);
  map<int,int> mp;
  rep(i,n){
    cin>>a[i];
    mp[a[i]]++;
  }


  if(mp[0]!=1||a[0]!=0){
    cout<<0<<endl;
    return 0;
  }

  sort(all(a));

  int ans=1;
  
  FOR(i,1,a[n-1]+1){
    if(mp[i]==0){
      ans=0;
      break;
    }
    int res=power(2,(mp[i]*(mp[i]-1)/2));
    res*=power((power(2,mp[i-1])-1),mp[i]);
    res%=M;
    ans*=res;
    ans%=M;
    //cout<<ans<<' '<<res<<endl;
  }

  cout<<ans<<endl;

}
