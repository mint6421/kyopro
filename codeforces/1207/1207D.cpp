
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
#define int ll
#define vi vector<int>
#define PP pair<P,int>


int fac[310000];


int fac_init(int n){
  fac[0]=1;
  FOR(i,1,n+1){
    fac[i]=fac[i-1]*i;
    fac[i]%=M;
  }
}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin>>n;
  vector<PP> v(n);
  rep(i,n){
    P p;
    cin>>p.F>>p.S;
    v[i]=PP(p,i);
  }
  fac_init(n);

  int a=1;
  sort(all(v));
  rep(i,n){
    int j=i;
    while(j<n&&v[i].F.F==v[j].F.F) j++;
    a*=fac[j-i];
    a%=M;
    i=j-1;
  }

  vector<PP> w;
  rep(i,n){
    w.PB(PP(P(v[i].F.S,v[i].F.F),v[i].S));
  }
  sort(all(w));

  int b=1;
  rep(i,n){
    int j=i;
    while(j<n&&w[i].F.F==w[j].F.F) j++;
    b*=fac[j-i];
    b%=M;
    i=j-1;
  }

  int c=1;
  rep(i,n){
    int j=i;
    while(j<n&&v[i].F.F==v[j].F.F&&v[i].F.S==v[j].F.S) j++;
    if(j<n&&v[i].F.S>v[j].F.S) c=0;
    else{
      c*=fac[j-i];
      c%=M;
    }
    i=j-1;
  }

  cout<<(fac[n]-a-b+c+2*M)%M<<endl;
}
