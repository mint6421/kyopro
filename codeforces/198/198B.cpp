
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
  string s[2];
  int n,k;
  
  cin>>n>>k;
  rep(i,2){
    cin>>s[i];
  }

  int dp[2][110000];

  rep(i,2){
    rep(j,n+1){
      dp[i][j]=inf;
    }
  }

  queue<P> q;
  dp[0][0]=0;
  q.push(P(0,0));
  bool flag=false;

  while(!q.empty()){
    P p=q.front(); q.pop();
    int x=p.F;
    int y=p.S;
    //cout<<x<<' '<<y<<endl;
    
    if(y>0){
      if(dp[x][y]+1<dp[x][y-1]&&dp[x][y]<y-1){
        if(s[x][y-1]!='X'){
          dp[x][y-1]=dp[x][y]+1;
          q.push(P(x,y-1));
        }
      }
    }
    if(y+1>=n||y+k>=n){
      flag=true;
      break;
    }

    if(dp[x][y]+1<dp[x][y+1]&&s[x][y+1]!='X'){
      dp[x][y+1]=dp[x][y]+1;
      q.push(P(x,y+1));
    }

    if(dp[x][y]+1<dp[(x+1)%2][y+k]){
      if(s[(x+1)%2][y+k]=='X') continue;
      dp[(x+1)%2][y+k]=dp[x][y]+1;
      q.push(P((x+1)%2,y+k));
    }
  }

  /*
  rep(i,2){
    rep(j,n){
      cout<<dp[i][j]<<' ';
    }
    cout<<endl;
  }
  */


  cout<<(flag?"YES":"NO")<<endl;
}
