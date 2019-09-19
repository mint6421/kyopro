
#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX
#define INF LLONG_MAX
#define ll long long
#define ull unsigned long long
#define M 998244353
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

int n,a,b,k;
map<int,int> ma,mb;

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  cin>>n>>a>>b>>k;
  fac_init(n);

  rep(i,n+1){
    int m=comb(n,i);
    ma[a*i]=m;
    mb[b*i]=m;
  }

  int ans=0;
  rep(i,n+1){
    int res=ma[a*i]*mb[k-a*i];
    res%=M;
    ans+=res;
    ans%=M;
  }

  cout<<ans<<endl;


}
