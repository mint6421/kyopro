
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
#define vi vector<int>

int c,n;
int a[110];
int dp[100100];


main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin>>c>>n;
  rep(i,n){
    cin>>a[i];
  }

  rep(i,100100){
    dp[i]=inf;
  }
  dp[0]=0;
  rep(i,n){
    rep(j,c+1){
      if(j+a[i]>c) break;
      dp[j+a[i]]=min(dp[j+a[i]],dp[j]+1);
    }
  }


 cout<<(dp[c]==inf?-1:dp[c])<<endl;

}
