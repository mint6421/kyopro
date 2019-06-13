
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


main(){
  int na,nb;
  cin>>na>>nb;
  vector<int> a(na),b(nb);
  rep(i,na){
    cin>>a[i];
  }
  rep(i,nb){
    cin>>b[i];
  }

  int dp[1010][1010]={};

  rrep(i,na){
    rrep(j,nb){
      if(i==na&&j==nb) continue;
      if((i+j)%2==0){
        if(i==na) dp[i][j]=b[j]+dp[i][j+1];
        else if(j==nb) dp[i][j]=a[i]+dp[i+1][j];
        else dp[i][j]=max(a[i]+dp[i+1][j],b[j]+dp[i][j+1]);
      }else{
        if(i==na) dp[i][j]=dp[i][j+1];
        else if(j==nb) dp[i][j]=dp[i+1][j];
        else dp[i][j]=min(dp[i+1][j],dp[i][j+1]);
      }
    }
  }

  cout<<dp[0][0]<<endl;
}
