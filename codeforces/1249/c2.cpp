
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




ll power(ll x,ll k){
  ll ret=1;
  while(k>0){
    if(k&1) (ret*=x) ;
    (x*=x) ;
    k >>= 1;
  }
  return ret;
}

vi c;

void f(int i){
  int s=power(3,i);
  if(s>2*(int)1e18) return;
  c.PB(s);
  //cout<<s<<endl;
  
  f(i+1);
}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  f(0);

  int q;
  cin>>q;
  while(q--){
    int n;
    cin>>n;

    int s=0;
    int i=0;
    while(s<n){
      s+=c[i];
      i++;
    }
    i--;
    while(i>=0){
      if(s-c[i]>=n){
        s-=c[i];
      }
      i--;
    }

    cout<<s<<endl;
  }
  

}
