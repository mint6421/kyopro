
#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX
#define INF LLONG_MAX
#define ll long long
#define ull unsigned long long
#define M (int)(998244353)
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
#define int ull
#define vi vector<int>
#define IP pair<int,P>
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

int fac[310000];

int inv(int x){
  if(x==1) return 1;
  return (M-M/x)*inv(M%x)%M;
}


int comb(int n,int k){
  int x=(fac[k]*fac[n-k])%M;
  return (fac[n]*inv(x))%M;
}

int fac_init(int n){
  fac[0]=1;
  FOR(i,1,n+1){
    fac[i]=fac[i-1]*i;
    fac[i]%=M;
  }
}

signed main(){
  int n;
  cin>>n;
  fac_init(2*n+1);
  string s;
  cin>>s;

  int ans=1;
  int i=0;
  while(i<n){
    int j=i;
    while(j<n&&s[i]==s[j]) j++;
    int m=j-i;
    ans*=(comb(2*m,m)*inv(m+1))%M;
    ans%=M;
    i=j;
  }

  cout<<ans<<endl;
}
