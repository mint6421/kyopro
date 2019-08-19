

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

string s;
int dp[200100];

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  dp[1]=1;
  dp[2]=1;

  cin>>s;
  rep(i,s.size()+1){
    if(i-3>=0)
      dp[i]=max(dp[i],dp[i-3]+2);
    FOR(j,1,3){
      if(i-j*2>=0&&s.substr(i-j*2,j)!=s.substr(i-j,j))
        dp[i]=max(dp[i],dp[i-j]+1);
    }
  }

  cout<<dp[s.size()]<<endl;

}
