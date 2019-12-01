

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

int n;
string s;
int dp[30010][10];

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);
  
  cin>>n;
  cin>>s;
  rep(i,n+2){
    rep(j,10) dp[i][j]=inf;
  }

  rrep(i,n){
    rep(j,10){
      dp[i][j]=dp[i+1][j];
    }
    dp[i][s[i]-'0']=i+1;
  }

  int ans=0;
  rep(i,10){
    rep(j,10){
      rep(k,10){
        int it=dp[0][i];
        if(it==inf) continue;
        it=dp[it][j];
        if(it==inf) continue;
        it=dp[it][k];
        //cout<<i<<' '<<j<<' '<<k<<endl;
        if(it==inf) continue;
        //cout<<i<<' '<<j<<' '<<k<<endl;
        ans++;
      }
    }
  }

  cout<<ans<<endl;



}
