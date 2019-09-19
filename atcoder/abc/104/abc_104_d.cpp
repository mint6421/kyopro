
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

  string s;
  cin>>s;
  int fl=0,fr=0,a=0,c=0;
  rep(i,s.size()){
    if(s[i]=='C') c++;
    if(s[i]=='?') fr++;
  }

  int ans=0;
  rep(i,s.size()){
    if(s[i]=='A') a++;
    else if(s[i]=='C') c--;
    else {
      if(s[i]=='?') fr--;
      int res=a*power(3,fl)%M+fl*power(3,fl-1)%M;
      res%=M;
      res*=c*power(3,fr)%M+fr*power(3,fr-1)%M;
      res%=M;
      ans+=res;
      ans%=M;
      if(s[i]=='?') fl++;
    }
    //cout<<ans<<endl;
  }

  cout<<ans<<endl;


}
