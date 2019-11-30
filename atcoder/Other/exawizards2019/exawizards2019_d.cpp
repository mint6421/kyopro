

#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX
#define INF LLONG_MAX
#define ll long long
#define ull unsigned long long
#define M (int)(1e9+7)
#define P pair<int,int>
#define FOR(i,m,n) for(int i=(int)m;i<(int)n;i++)
#define RFOR(i,m,n) for(int i=(int)m;i>=(int)n;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,n,0)
#define all(a) a.begin(),a.end()
const int vx[4] = {0,1,0,-1};
const int vy[4] = {1,0,-1,0};
#define F first
#define S second
#define PB push_back
#define EB emplace_back
#define int ll
#define vi vector<int>
#define IP pair<int,P>
#define PI pair<P,int>
#define PP pair<P,P>
#define Yes(f){cout<<(f?"Yes":"No")<<endl;}
#define YES(f){cout<<(f?"YES":"NO")<<endl;}
int Madd(int x,int y) {return (x+y)%M;}
int Msub(int x,int y) {return (x-y+M)%M;}
int Mmul(int x,int y) {return (x*y)%M;}


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n,x;
  cin>>n>>x;
  vi s(n);
  rep(i,n){
    cin>>s[i];
  }
  sort(all(s));
  vector<vi> dp(n+1,vi(x+1,0));
  
  rep(j,x+1) dp[0][j]=j;
  rep(i,n){
    rep(j,x+1){
      dp[i+1][j]=Madd(dp[i+1][j],dp[i][j%s[i]]);
      dp[i+1][j]=Madd(dp[i+1][j],Mmul(dp[i][j],i));
    }
  }

  cout<<dp[n][x]<<endl;

}
