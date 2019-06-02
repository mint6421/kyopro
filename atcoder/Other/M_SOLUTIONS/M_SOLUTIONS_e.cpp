
#include<bits/stdc++.h>
using namespace std;
#define inf 1000000000
#define INF 1000000000000000
#define ll long long
#define ull unsigned long long
#define M (int)(1e6+3)
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


ll power(ll x,ll k){
  ll ret=1;
  while(k>0){
    if(k&1) (ret*=x) %= M;
    (x*=x) %= M;
    k >>= 1;
  }
  return ret;
}

int fact[M+10];
int ifact[M+10];

main(){
  fact[0]=1;
  FOR(i,1,M+1){
    fact[i]=(1LL*fact[i-1]*i)%M;
    ifact[i]=power(fact[i],M-2);
  }

  int q;
  cin>>q;
  while(q--){
    int x,d,n;
    cin>>x>>d>>n;
    if(d==0){
      cout<<power(x,n)<<endl;
    }else{
      int t=(1LL*x*power(d,M-2))%M;
      
      if(t<=M&&M<=t+n-1){
        cout<<0<<endl;
      }else{
        cout<<(((1LL*fact[t+n-1]*ifact[t-1])%M)*power(d,n)%M)<<endl;
      }
    }
  }
}
