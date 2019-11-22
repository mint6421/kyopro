

#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX
#define INF LLONG_MAX
#define ll long long
#define ull unsigned long long
#define M 100000
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
#define MPlus(x,y) {x=(x+y)%M;}
#define MSub(x,y) {x=(x-y+M)%M;}
#define MMul(x,y) {x=(x*y)%M;}

int k,r;
bool b1[3000010],b2[3000010];
int dp[3000010][2][2];

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  cin>>k>>r;
  rep(i,r){
    int t,a;
    cin>>t>>a;
    if(t==1) b1[a]=true;
    else b2[a]=true;
  }

  dp[0][0][0]=1;

  FOR(i,1,k+1){
    if(!b1[i]){
      MPlus(dp[i][0][1],dp[i-1][0][0]+dp[i-1][1][0]);
    }
    if(!b2[i]){
      MPlus(dp[i][1][0],dp[i-1][0][0]+dp[i-1][0][1]);
    }
    if(!b1[i]&&!b2[i]){
      MPlus(dp[i][0][0],dp[i-1][0][0]+dp[i-1][0][1]+dp[i-1][1][0]);
    }
  }

  cout<<dp[k][0][0]<<endl;


}
