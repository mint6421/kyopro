
#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX
#define INF LLONG_MAX
#define ll long long
#define ull unsigned long long
#define M (int)(1e9+9)
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

int n;
int dp[110000];

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin>>n;
  dp[0]=1;
  FOR(i,1,10){
    rep(j,100000){
      dp[i+j]+=dp[j];
      dp[i+j]%=M;
    }
  }

  FOR(i,1,100000){
    dp[i]+=dp[i-1];
    dp[i]%=M;
  }

  while(n--){
    int a;
    cin>>a;
    cout<<dp[a/111111]<<endl;

  }

}
