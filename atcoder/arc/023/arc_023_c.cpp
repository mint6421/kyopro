
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
#define int ll
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
  rep(i,n){
    cin>>a[i];
  }

  int ans=1;
  int i=0;
  while(i<n){
    int s=a[i];
    if(s!=-1){
      i++;
      continue;
    }
    s=a[i-1];
    int j=i;
    while(a[j]==a[i]) j++;
    int t=a[j];
    //cout<<t-s+1<<' '<<j-i<<endl;
    //cout<<c[t-s+1][j-i]<<endl;
    int nn=t-s+j-i,kk=j-i;
    //cout<<nn<<' '<<kk<<endl;
    int res=1;
    FOR(k,nn-kk+1,nn+1){
     
      res*=k;
      res%=M;
    }
    FOR(k,1,kk+1){
      //cout<<k<<endl;
      res*=power(k,M-2);
      res%=M;
    }

    ans*=res;
    ans%=M;
    i=j;
  }

  cout<<ans<<endl;

}
