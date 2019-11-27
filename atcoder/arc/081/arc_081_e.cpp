

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

vector<vi> calcNext(string s){
  int n=s.size();
  vector<vi> res(n+1,vi(26,n));
  rrep(i,n-1){
    rep(j,26) res[i][j]=res[i+1][j];
    res[i][s[i]-'a']=i;
  }

  return res;
}


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  string s;
  cin>>s;
  int n=s.size();

  vector<vi> next=calcNext(s);

  vi dp(n+1,inf);
  vector<pair<char,int>> recon(n+1,{'?',n});

  dp[n]=1;
  
  rrep(i,n-1){
    rep(j,26){ 
      if(next[i][j]==n){
        if(dp[i]>1){
          dp[i]=1;
          recon[i]={'a'+j,n};
        }
      }else if(dp[i]>dp[next[i][j]+1]+1){
        dp[i]=dp[next[i][j]+1]+1;
        recon[i]={'a'+j,next[i][j]+1};
      }
    }
  }

  
  string ans="";
  int it=0;
  while(it<n){
    auto p=recon[it];
    ans+=p.F;
    it=p.S;
    
  }

  cout<<ans<<endl;


}
