
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


ll f(ll n){
  ll res=0;
  ll r=1;
  queue<ll> q;
  q.push(1);
  q.push(2);

  while(n>0){
    ll t=min(n,r);
    ll m=q.front(); q.pop();
    t%=M;
    ll ma=m%M;
    ll ta=(m+t-1)%M;
    ll p=t*ta%M;
    res+=p;
    res%=M;
    n-=r;
    q.push(m+2*r);
    r*=2;
//    cout<<n<<' '<<res<<endl;
  }
//  cout<<res<<endl;

  return res;
}



int main(){
  ll a,b;
  cin>>a>>b;
  cout<<(f(b)-f(a-1)+M)%M<<endl;
}
