
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

int n;
int a[300000];
int b[300000];

main(){
  cin>>n;

  FOR(i,1,n+1){
    cin>>a[i];
  }

  int dp[300000]={};
  dp[0]=1;
  FOR(i,1,n+1){
    dp[i]=dp[i-1];
    if(b[a[i]]+1==i||b[a[i]]==0){
      b[a[i]]=i;continue;
    }

    dp[i]=dp[i-1]+1+dp[b[a[i]]]-1;
    b[a[i]]=i;
    dp[i]%=M;
  }
  /*
     rep(i,n){
     cout<<dp[i]<<' ';
     }cout<<endl;
     */

  cout<<dp[n]<<endl;
}
