
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

int n,m,y,z;
map<char,int> mp;
int itr[1000];
string b;


int dp[5010][1040][20]={};
bool use[5010][1040][20]={};


int d(){
 use[0][0][m]=true;

 rep(i,n+1){
   rep(j,(1<<m)){
     rep(k,m+1){
       if(j==0) continue;
       dp[i][j][k]=-inf;
     }
   }
 }

 

 rep(i,n){
   int it=itr[b[i]];
   int p=mp[b[i]];
   rep(j,(1<<m)){
     rep(k,m+1){
       if(use[i][j][k]){
         dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]);
         dp[i+1][j|(1<<it)][it]=max(dp[i+1][j|(1<<it)][it],dp[i][j][k]+p+y*(it==k));
         use[i+1][j][k]=true;
         use[i+1][j|(1<<it)][it]=true;
         //cout<<' '<<dp[i+1][j|(1<<it)][it]<<endl;
       }
      }
    }
  }

  int res=0;
  /*
  rep(i,n+1){
    rep(j,(1<<m)){
      rep(k,m+1){
        cout<<dp[i][j][k]<<' ';
      }
      cout<<endl;
    }
    cout<<endl;
  }
  */

  rep(j,(1<<m)){
    rep(k,m){
      if(!use[n][j][k]) continue;
        res=max(res,dp[n][j][k]+z*(j==(1<<m)-1));
    }
  }

  return res;

}


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  cin>>n>>m>>y>>z;
  rep(i,m){
    char c;
    int p;
    cin>>c>>p;
    itr[c]=i;
    mp[c]=p;
  }
  cin>>b;

  cout<<d()<<endl;

}
