
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


int ans=inf;
vector<int> v(4);

void f(int a,int b,int c){
  vector<int> d;
  d.PB(a);
  d.PB(b);
  d.PB(c);

  int dp[10][100];
  rep(i,4){
    rep(j,100){
      dp[i][j]=inf;
    }
  }
  dp[0][0]=0;
  rep(i,3){
    rep(j,40){
      if(i)
        dp[i][j]=min(dp[i][j],dp[i-1][j]);
      dp[i][j+d[i]]=min(dp[i][j+d[i]],dp[i][j]+1);
    }
  }

  int sum=0;
  rep(i,4){
    sum+=dp[2][v[i]];
  }

  ans=min(ans,sum);
}


main(){
  rep(i,4){
    cin>>v[i];
  }

  FOR(a,1,31){
    FOR(b,a+1,31){
      FOR(c,b+1,31){
        f(a,b,c);
      }
    }
  }

  cout<<ans<<endl;
}
