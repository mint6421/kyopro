
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
#define int ll
void init(){
  cin.tie(0);
  ios::sync_with_stdio(false);
}



int a[210000],dp[210000];
int l,n;
int ans;

void f(){
  FOR(i,1,n+1){
    if(i%2){
      dp[i]=dp[i-1]+l-(a[i/2+1]-a[i/2])-2*(a[i]-a[i/2+1]);
    }else{
      dp[i]=dp[i-1]+l-2*(a[i]-a[i/2]);
    }
    //cout<<dp[i]<<' ';
    ans=max(ans,dp[i]);
  }
  cout<<endl;
}

main(){
  cin>>l>>n;
  FOR(i,1,n+1){
    cin>>a[i];
  }
  
  f();

  reverse(a+1,a+n+1);

  FOR(i,1,n+1){
    a[i]=l-a[i];
  }


  f();

  cout<<ans<<endl;
}
