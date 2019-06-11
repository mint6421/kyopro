
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


int n,m;
bool b[200000];
int dp[200000];

main(){
  cin>>n>>m;
  rep(i,m){
    int a;
    cin>>a;
    b[a]=true;
  }

  dp[0]=1;

  rep(i,n){
    if(!b[i+1]) dp[i+1]+=dp[i];
    if(!b[i+2]) dp[i+2]+=dp[i];
    dp[i+1]%=M;
    dp[i+2]%=M;
  }

  

  cout<<dp[n]<<endl;
}
