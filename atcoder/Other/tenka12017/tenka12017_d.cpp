
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

ll n,k,ans;
ll a[110000],b[110000];


int main(){
  cin>>n>>k;
  rep(i,n){
    cin>>a[i]>>b[i];
  }

  for(ll i=1;i<=(1LL<<30);i<<=1){
    if(k&i){
      ll sum=0,t=(k^i)|(i-1);
      rep(j,n){
        if((a[j]&t)==a[j])
          sum+=b[j];
      }
      ans=max(ans,sum);
    }
  }
  
  ll sum=0;
  rep(i,n){
    if((a[i]&k)==a[i])
      sum+=b[i];
  }
  ans=max(ans,sum);

  cout<<ans<<endl;
}
