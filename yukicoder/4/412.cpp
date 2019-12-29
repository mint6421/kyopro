

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

  vi a(3);
  rep(i,3){
    cin>>a[i];
  }

  int n;
  cin>>n;
  vi e(n);
  rep(i,n){
    cin>>e[i];
  }
  sort(all(e));

  vector<vi> dp(n+1,vi(4,0));
  dp[0][0]=1;
  rep(i,n){
    int cnt=0;
    rep(j,3){
      if(a[j]<=e[i]) cnt++;
    }

    rep(j,4){
      if(cnt==j){
        dp[i+1][j]+=dp[i][j]*2;
      }else{
        dp[i+1][j]+=dp[i][j];
        dp[i+1][j+1]+=dp[i][j];
      }
    }
  }

  cout<<dp[n][3]<<endl;


}
