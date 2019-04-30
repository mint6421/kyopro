
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
void init(){
  cin.tie(0);
  ios::sync_with_stdio(false);
}


int n,m,l;
int t[110000];

main(){
  cin>>n>>m>>l;
  vector<P> v;
  vector<vector<int>> w(n+1);
  rep(i,n){
    cin>>t[i+1];
  }

  rep(i,m){
    int x,a;
    cin>>x>>a;
    v.PB(P(x,a));
  }
 

  rep(i,l){
    int y,b;
    cin>>y>>b;
    w[y].PB(b);
  }
  rep(i,n+1){
    sort(all(w[i]));
  }

  vector<P> a;
  vector<int> b;

  rep(i,m){
    int x=v[i].F,y=v[i].S;
    auto it = upper_bound(all(w[x]),y+t[x]);
    if(it!=w[x].end()){
      a.PB(P(*it+t[x],y));
    }else{
      b.PB(y);
    }
  }
  sort(all(a));
  sort(all(b));
  int ans=0,t=0;
  rep(i,a.size()){
    if(a[i].S<=t) continue;
    ans+=2;
    t=a[i].F;
  }
  
  if(upper_bound(all(b),t)!=b.end())
    ans++;

  cout<<ans<<endl;

}
