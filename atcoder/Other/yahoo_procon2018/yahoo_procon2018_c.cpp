

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

int n,x[20],c[20],v[20];
int dp[20][1<<20];
int memo[20][1<<20];


int f(int m,int bit){
  //cout<<m<<' '<<bit<<endl;
  if(memo[m][bit]>=0) return memo[m][bit];
  if(m==n) return 0;

  int s=INF;
  rep(i,n){
    if(bit&(1<<i)) s=min(s,f(m+1,bit-(1<<i)));
  }
  int b=dp[m][bit];

  return memo[m][bit]=max(s,b);
}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  cin>>n;
  rep(i,n){
    cin>>x[i];
  }
  rep(i,n){
    cin>>c[i];
  }
  rep(i,n){
    cin>>v[i];
  }

  rep(m,n+1){
    int s=0;
    rep(i,m) s+=x[i];

    rep(bit,(1<<n)){
      int co=0,va=0;
      rep(i,n){
        if(bit&(1<<i)){
          co+=c[i];
          va+=v[i];
        }
      }
      if(co<=s) dp[m][bit]=va;
      else dp[m][bit]=0;
    }

    rep(bit,(1<<n)){
      rep(i,n){
        if(bit&(1<<i)){
          dp[m][bit]=max(dp[m][bit],dp[m][bit^(1<<i)]);
        }
      }
    }
  }

  rep(i,n+1){
    rep(bit,(1<<n)){
      memo[i][bit]=-1;
    }
  }

  cout<<f(0,(1<<n)-1)<<endl;


}
