
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

int dp[210000][3];

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);


  int q;
  cin>>q;
  while(q--){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;


    rep(i,n){
      if(i%3==0){
        dp[i+1][0]=dp[i][0]+(s[i]!='R');
        dp[i+1][1]=dp[i][1]+(s[i]!='G');
        dp[i+1][2]=dp[i][2]+(s[i]!='B');
      }else if(i%3==1){
        dp[i+1][0]=dp[i][0]+(s[i]!='G');
        dp[i+1][1]=dp[i][1]+(s[i]!='B');
        dp[i+1][2]=dp[i][2]+(s[i]!='R');
      }else{
        dp[i+1][0]=dp[i][0]+(s[i]!='B');
        dp[i+1][1]=dp[i][1]+(s[i]!='R');
        dp[i+1][2]=dp[i][2]+(s[i]!='G');
      }

    }

    int ans=inf;
    rep(i,n-k+1){
      ans=min(ans,dp[i+k][0]-dp[i][0]);
      ans=min(ans,dp[i+k][1]-dp[i][1]);
      ans=min(ans,dp[i+k][2]-dp[i][2]);
    }

    cout<<ans<<endl;
  }


}
