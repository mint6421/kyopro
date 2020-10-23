
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


ll h,n;
ll d[300000];
ll sum,mi,m;

int main(){
  cin>>h>>n;
  rep(i,n){
    cin>>d[i];
    sum+=d[i];
    m+=d[i];
    mi=min(mi,m);
  }


  ll hh=h;
  rep(i,n){
    hh+=d[i];
    if(hh<=0){
      cout<<i+1<<endl;
      return 0;
    }
  }
  if(hh>=h){
    cout<<-1<<endl;
    return 0;
  }
 
  ll ans=0;

  if(sum!=0)
    ans=(h+mi-sum-1)/(-sum);

  h+=sum*ans;
  ans*=n;
//  cout<<sum<<' '<<ans<<endl;
//  cout<<h<<endl;
  rep(i,n+1){ 
    if(h<=0){
      cout<<ans+i<<endl;
      return 0;
    }
    h+=d[i];
  }
}

