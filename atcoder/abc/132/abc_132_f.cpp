

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

int n,k;
int dp[110][110000];
int sdp[110000];
int num[110000];

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);
  
  cin>>n>>k;

  int it=0;
  for(int i=1;i<=n;){
    int j=n/i;
    if(i<=j){
      num[it++]=1;
      i++;
    }else{
      num[it++]=n/j-i+1;
      i=n/j+1;
    }
  }

  dp[0][0]=1;
  rep(i,k){
    memset(sdp,0,sizeof(sdp));
    rep(j,it+1) sdp[j+1]=Madd(sdp[j],dp[i][j]);
    rep(j,it) dp[i+1][j]=Mmul(sdp[it-j],num[j]);
  }

  

  int ans=0;
  rep(j,it+1) ans=Madd(ans,dp[k][j]);

  cout<<ans<<endl;



}
