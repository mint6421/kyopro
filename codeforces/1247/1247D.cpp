
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


map<int,int> prime_factor(int n){
  map<int,int> ret;
  for(int i=2;i*i<=n;i++){
    while(n%i==0){
      ret[i]++;
      n/=i;
    }
  }
  if(n!=1) ret[n]=1;

  return ret;
}



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
  
  int n,k;
  cin>>n>>k;
  vi a(n);
  rep(i,n){
    cin>>a[i];
  }
  sort(all(a));

  int ans=0;
  map<int,int> p;

  rep(i,n){
    int s=1,t=1;
    map<int,int> mp=prime_factor(a[i]);
    for(P m:mp){
      int u=((m.S+k-1)/k)*k;
      s*=power(m.F,u-m.S);
      t*=power(m.F,m.S-(m.S/k)*k);
    }
    ans+=p[s];
    p[t]++;
    //cout<<a[i]<<' '<<s<<' '<<t<<endl;
  }

  cout<<ans<<endl;


}
