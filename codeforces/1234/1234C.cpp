
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

int n,q;
bool dp[200010][2][2];

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  cin>>q;
  while(q--){
    int n;
    cin>>n;
    rep(i,n+1){
      rep(j,2){
        dp[i][0][j]=false;
        dp[i][1][j]=false;
      }
    }

    string s[2];
    cin>>s[0]>>s[1];
    dp[0][0][0]=true;

    FOR(i,1,n+1){
      rep(j,4){
        if(s[j%2][i-1]<='2'){
          //cout<<i<<' '<<j<<endl;
          dp[i][j%2][0]|=dp[i-1][j%2][0];
        }else{
          dp[i][j%2][1]|=dp[i-1][j%2][0];
          dp[i][j%2][0]|=dp[i][(j+1)%2][1];
        }
      }
    }

    /*
    rep(i,2){
      rep(j,n+1){
        cout<<dp[j][i][0]<<' ';
      }
      cout<<endl;
    }
    */

    YES(dp[n][1][0]);
  }



}
