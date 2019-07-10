
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

bool dp[1100][110000];

main(){
  int n;
  cin>>n;
  vector<int> v(n+1);
  rep(i,n){
    cin>>v[i+1];
  }

 
  dp[0][0]=true;
  dp[1][v[1]]=true;

  FOR(i,2,n+1){
    rep(j,100010){
      dp[i][j]|=dp[i-1][j];
      dp[i][j+v[i]]|=dp[i-2][j];
      if(dp[i][j]){
        //cout<<i<<' '<<j<<endl;
      }
    }
  }

  int res=0;
  rep(j,100010){
    if(dp[n][j]) res=j;
  }

  cout<<res<<endl;

  vector<int> ans;
  RFOR(i,n,1){
   if(dp[i][res]&&!dp[i-1][res]){
    ans.PB(i);
    res-=v[i];
   }
  }

  reverse(all(ans));
  rep(i,ans.size()){
    cout<<ans[i]<<' ';
  }
  cout<<endl;



}
