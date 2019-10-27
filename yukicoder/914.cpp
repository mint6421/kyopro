
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
#define Yes(f){cout<<(f?"Yes":"No")<<endl;}
#define YES(f){cout<<(f?"YES":"NO")<<endl;}

int n,m,k;
bool dp[20][1000];
int a[20][20];

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  cin>>n>>m>>k;
  rep(i,n){
    rep(j,m){
      cin>>a[i][j];
    }
  }

  dp[0][0]=true;

  rep(i,n){
    rep(j,m){
      rep(k,600){
        
        dp[i+1][a[i][j]+k]|=dp[i][k];
      }
    }
  }


  rrep(i,k){
    if(dp[n][i]){
      cout<<k-i<<endl;
      return 0;
    }
  }

  cout<<-1<<endl;

}
