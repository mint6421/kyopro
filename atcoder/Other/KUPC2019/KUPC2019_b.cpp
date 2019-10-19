
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

int n,m,w;
int dp[11000];
bool d[110][110];
bool c[110];
vector<P> v,vv;

P f(int k){
  if(c[k]) return P(0,0);
  c[k]=true;
  P p=v[k];

  rep(i,n){
    if(d[k][i]){
      P q=f(i);
      p.F+=q.F;
      p.S+=q.S;
    }
  }

  return p;
}


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  cin>>n>>m>>w;
  rep(i,n){
    int a,b;
    cin>>a>>b;
    v.PB(P(a,b));
  }
  rep(i,m){
    int a,b;
    cin>>a>>b;
    a--;b--;
    d[a][b]=true;
    d[b][a]=true;
  }

  rep(i,n){
    if(c[i]) continue;
    vv.PB(f(i));
  }

  int ans=0;

  for(P p:vv){
    //cout<<p.F<<' '<<p.S<<endl;
    rrep(i,w+1){
      if(i+p.F>w) continue;
      dp[i+p.F]=max(dp[i+p.F],dp[i]+p.S);
      //cout<<' '<<i+p.F<<' '<<dp[i+p.F]<<endl;
      ans=max(ans,dp[i+p.F]);
    }
  }

  cout<<ans<<endl;
}


  


