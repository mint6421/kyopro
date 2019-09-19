
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
#define IP pair<int,P>
#define PP pair<P,P>


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);


  int n;
  cin>>n;
  int dp[110][4][4][4]={};
  dp[0][0][0][0]=1;

  rep(i,n){
    rep(a,4)rep(b,4)rep(c,4)rep(d,4){
      if(a==1&&b==3&&d==2)continue;
      if(b==1&&c==3&&d==2)continue;
      if(a==1&&c==3&&d==2)continue;
      if(b==1&&c==2&&d==3)continue;
      if(b==3&&c==1&&d==2)continue;
      dp[i+1][b][c][d]+=dp[i][a][b][c];
      dp[i+1][b][c][d]%=M;
    }
  }

  int ans=0;
  rep(a,4)rep(b,4)rep(c,4){
    ans+=dp[n][a][b][c];
    ans%=M;
  }

  cout<<ans<<endl;

}
