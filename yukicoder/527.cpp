
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
int dp[110][110000];
P s[110];
int v;

main(){
  cin>>n;
  rep(i,n){
    cin>>s[i].F>>s[i].S;
  }
  cin>>v;

  FOR(j,s[0].S,100010){
    dp[0][j]=s[0].F;
  }


  

  FOR(i,1,n){
    rep(j,100010){
      dp[i][j]=max(dp[i][j],dp[i-1][j]);
      dp[i][j+s[i].S]=max(dp[i][j+s[i].S],dp[i-1][j]+s[i].F);
    }
  }

  int l=-1,r=-1;
  FOR(j,1,100010){
    if(dp[n-1][j]==v){
      l=j;
      while(j<100010&&dp[n-1][l]==dp[n-1][j]) j++;
      r=j;
      r--;
      break;
    }
  }

  cout<<l<<endl;
  if(r>100000){
    cout<<"inf"<<endl;
  }else{
    cout<<r<<endl;
  }

}

