

#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX
#define INF LLONG_MAX
#define ll long long
#define ull unsigned long long
#define M (int)(1e9+7)
#define P pair<int,int>
#define FOR(i,m,n) for(int i=(int)m;i<(int)n;i++)
#define RFOR(i,m,n) for(int i=(int)m;i>=(int)n;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,n,0)
#define all(a) a.begin(),a.end()
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
int Madd(int x,int y) {return (x+y)%M;}
int Msub(int x,int y) {return (x-y+M)%M;}
int Mmul(int x,int y) {return (x*y)%M;}



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

  int n,a,b;
  cin>>n>>a>>b;
  vi v(n);
  rep(i,n){
    cin>>v[i];
  }

  sort(all(v));
  if(a==1){
    rep(i,n){
      cout<<v[i]<<endl;
    }
    return 0;
  }

  while(b&&v[0]*a<v[n-1]){
    v[0]*=a;
    sort(all(v));
    b--;
  }

  rep(i,n){
    if(i>=(b%n))
      cout<<((v[i]%M)*power(a,b/n))%M<<endl;
  }

  rep(i,n){
    if(i<(b%n))
      cout<<((v[i]%M)*power(a,b/n+1))%M<<endl;
  }


}
