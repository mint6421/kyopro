
#include<bits/stdc++.h>
using namespace std;
#define inf 1000000000
#define INF 1000000000000000
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
void init(){
  cin.tie(0);
  ios::sync_with_stdio(false);
}


ll a,b;
ll ans;
ll res=INF;

int main(){
  cin>>a>>b;
  ll x=abs(b-a);
//  cout<<x<<endl;
  vector<ll> v;
  for(ll i=1;i*i<=x;i++){
    if(x%i!=0) continue;
//    cout<<i<<endl;
    v.PB(x/i);
    if(x/i!=i)
      v.PB(i);
  }

  for(ll i:v){
    if(x%i!=0) continue;
//    cout<<i<<endl;
    ll aa=((a+i-1)/i)*i;
    ll bb=b+aa-a;
//    cout<<aa<<' '<<bb<<endl;
    if(res>aa*bb/__gcd(aa,bb)){
      res=aa*bb/__gcd(aa,bb);
      ans=aa-a;
    }
  }

  cout<<ans<<endl;
}

