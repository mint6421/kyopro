

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

int dp[210000][5];
vi a;

int cost(int i,int s){
  if(s==0) return a[i];
  else if(s==4) return a[i];
  else if(s==1||s==3){
    if(a[i]%2==0&&a[i]>0) return 0;
    else if(a[i]>0) return 1;
    else return 2;
  }else{
    if(a[i]%2==0) return 1;
    else return 0;
  }
}


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int l;
  cin>>l;
  a = vi(l);
  rep(i,l){
    cin>>a[i];
  }

  rep(i,200100){
    rep(j,5){
      dp[i][j]=inf;
    }
  }
  dp[0][0]=0;

  rep(i,l){
    rep(j,5){
      FOR(k,j,5){
        dp[i+1][k]=min(dp[i+1][k],dp[i][j]+cost(i,k));
      }
    }
  }

  int ans=inf;
  rep(j,5) ans=min(ans,dp[l][j]);

  cout<<ans<<endl;

}
