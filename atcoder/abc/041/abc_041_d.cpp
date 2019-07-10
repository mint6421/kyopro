
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
int dp[1<<20];
int a[1<<20];

int dfs(int s){
  if(dp[s]) return dp[s];
  if(s==0) return dp[0]=1;

  int res=0;

  rep(i,n){
    if(s&(1<<i)){
      if(s&a[i]) continue;
      res+= dfs(s-(1<<i));
    }
  }

  return dp[s]=res;
}


main(){
  cin>>n>>m;


  rep(i,m){
    int x,y;
    cin>>x>>y;
    x--;y--;
    a[x]|=(1<<y);
  }

  cout<<dfs((1<<n)-1)<<endl;
}
