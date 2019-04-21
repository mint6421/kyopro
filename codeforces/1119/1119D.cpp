

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
ll a[110000];
vector<ll> v;

int main(){
  cin>>n;
  rep(i,n){
    cin>>a[i];
  }
  sort(a,a+n);

  FOR(i,1,n){
    v.PB(a[i]-a[i-1]);
  }
  
  sort(all(v));

 
  ll vsum[110000]={};
  rep(i,v.size()){
    vsum[i+1]+=v[i]+vsum[i];
  }

  int q;
  cin>>q;
  rep(i,q){
    ll x,y;
    cin>>x>>y;
    ll m = upper_bound(all(v),y-x)-v.begin();
   // cout<<m<<' '<<vsum[m]<<endl;
   if(i) cout<<' ';
    cout<<(n-m)*(y-x+1)+vsum[m];
  }
  cout<<endl;
  
}
