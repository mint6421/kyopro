
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


int n;
ll a[210000],b[210000];
map<ll,ll> mpa;
map<ll,ll> mpb;

int main(){
  cin>>n;

  FOR(i,1,n+1){
    cin>>a[i];
    b[i]=a[i];
    a[i]+=a[i-1];
  }
  rrep(i,n){
    b[i-1]+=b[i];
  }
  mpa[0]++;
  ll ansa=0,ansb=0;
  mpb[0]++;
  ll ans=INF;

  FOR(i,1,n+1){
    ansa+=mpa[a[i]];
    mpa[a[i]]++;
  }
  rrep(i,n){
    mpa[a[i]]--;
    ansa-=mpa[a[i]];
    ans=min(ans,ansa+ansb);
    ansb+=mpb[b[i]];
    mpb[b[i]]++;
  }

  cout<<ans<<endl;


}
