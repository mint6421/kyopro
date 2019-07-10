
#include<bits/stdc++.h>
using namespace std;
#define inf 1000000000
#define INF 1000000000000000
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
#define PP pair<P,int>
void init(){
  cin.tie(0);
  ios::sync_with_stdio(false);
}


int n,m,a;

main(){
  cin>>n>>m>>a;
  vector<PP> v(m);
  rep(i,m){
    cin>>v[i].F.S>>v[i].F.F>>v[i].S;
  }

  sort(all(v));

  int t=0;
  vector<PP> res;
  res.PB(PP(P(0,0),0));
  rep(i,m){
    if(t<v[i].F.S){
      t=v[i].F.F;
      res.PB(v[i]);
    }
  }
  res.PB(PP(P(n+1,n+1),0));

  int ans=0;
  FOR(i,1,res.size()-1){
    int sum=res[i].S;
    if(res[i].F.S-res[i-1].F.F!=1){
      sum-=a;
    }if(res[i+1].F.F-res[i].F.S!=1){
      sum-=a;
    }
    ans+=sum;
  }

  cout<<ans<<endl;
}
