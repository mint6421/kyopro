
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

int n,m;
int s[1100];
int dp[1100][1100][20];


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  cin>>n>>m;
  rep(i,m){
    string t;
    cin>>t;
    if(t=="Fizz") s[i]=3;
    else if(t=="Buzz") s[i]=5;
  }

  dp[0][0][0]=1;
  rep(i,n){
    rep(j,m+1){
      rep(k,15){
        rep(l,10){
          if(dp[i][j][k]==0) continue;
          if(i==0&&l==0) continue;
          int a=(10*k+l)%15;
          bool flag1=(a%3!=0)&(a%5!=0);
          if(j==m&&flag1){
            dp[i+1][j][a]+=dp[i][j][k];
            dp[i+1][j][a]%=M;
            continue;
          }

          bool flag=false;
          flag|=(s[j]==3&a%3==0&a%5!=0);
          flag|=(s[j]==5&a%5==0&a%3!=0);
          flag|=(s[j]==0&a==0);
          if(flag||flag1){
            dp[i+1][j+flag][a]+=dp[i][j][k];
            dp[i+1][j+flag][a]%=M;
          }

        }
      }
    }
  }

  int ans=0;
  rep(k,15){
    ans+=dp[n][m][k];
    ans%=M;
  }

  cout<<ans<<endl;


}
