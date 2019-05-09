
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


int dp[5100][5100];

void LCS(string s,string t){
  FOR(i,1,s.size()+1){
    FOR(j,1,t.size()+1){
      if(s[i-1]==t[j-1]){
        dp[i][j] = dp[i-1][j-1]+1;
      }
      dp[i][j] = max(dp[i][j],dp[i-1][j]);
      dp[i][j] = max(dp[i][j],dp[i][j-1]);
    }
  }
}

int main(){
  string s,t;
  cin>>s>>t;
  LCS(s,t);

  cout<<dp[s.size()][t.size()]+1<<endl;
}
