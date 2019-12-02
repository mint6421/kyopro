
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




ll power(ll x,ll k,ll m){
  ll ret=1;
  while(k>0){
    if(k&1) (ret*=x) %= m;
    (x*=x) %= m;
    k >>= 1;
  }
  return ret;
}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;
  cin>>s;
  int a[3]={};
  int t=0;
  rep(i,s.size()){
    if(s[i]=='^') t++;
    else{
      a[t]*=10;
      a[t]+=s[i]-'0';
    }
  }

  cout<<power(power(a[0]%M,a[1],M),a[2],M)<<' '<<power(a[0]%M,power(a[1]%(M-1),a[2],M-1)+M-1,M)<<endl;

}
