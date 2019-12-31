

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


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n,m;
  cin>>n>>m;
  vi d(n,0);
  rep(i,m){
    int a,b,c;
    cin>>a>>b>>c;
    a--;b--;
    d[a]+=c;
    d[b]-=c;
  }

  vi l,r;
  rep(i,n){
    if(d[i]<0){
      r.PB(i);
      d[i]=-d[i];
    }else if(d[i]>0){
      l.PB(i);
    }
  }

  vector<PI> ans;
  while(r.size()&&l.size()){
    int a=l.back(),b=r.back();
    int x=min(d[a],d[b]);
    ans.PB(PI(P(a+1,b+1),x));
    d[a]-=x;
    d[b]-=x;
    if(d[a]==0) l.pop_back();
    if(d[b]==0) r.pop_back();
  }

  cout<<ans.size()<<endl;
  for(auto x:ans){
    cout<<x.F.F<<' '<<x.F.S<<' '<<x.S<<endl;
  }




}
