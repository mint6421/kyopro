

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

int n,s,k;
int dp[101][20010];


int dfs(int m,int y){
  if(y<0) return 0;
  if(m==n-1) return 1;
  
  
  if(dp[m][y]>=0) return dp[m][y];

  int ret=0;
  for(int i=0;i*(n-m)<=y;i++){
    ret+=dfs(m+1,y-i*(n-m));
  }
  ret%=M;

  return dp[m][y]=ret;
}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  memset(dp,-1,sizeof(dp));
  cin>>n>>s>>k;
  s-=n*(n-1)/2*k;
  cout<<dfs(0,s)<<endl;


}
