
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


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int h,w,k;
  cin>>h>>w>>k;
  k--;
  int dp[110][10]={};
  dp[0][0]=1;

  rep(i,h){
    rep(j,(1<<w-1)){
      bool flag=false;
      rep(l,w-2){
        flag|=((j>>l)%4==3);
      }
      if(flag) continue;

      int x[10];
      rep(l,w) x[l]=l;

      rep(l,w-1){
        if((1<<l)&j) swap(x[l],x[l+1]);
      }

      rep(l,w){
        dp[i+1][x[l]]+=dp[i][l];
        dp[i+1][x[l]]%=M;
      }
    }
  }

  cout<<dp[h][k]<<endl;


}
