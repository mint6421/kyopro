
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
#define BB pair<P,bool>


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);
  int n,k;
  cin>>n>>k;
  vector<BB> v;
  rep(i,n){
    int l,r;
    cin>>l>>r;
    v.PB(BB(P(l,r),true));
  }

  vi ans;
  rep(l,201){
    vector<P> r;
    rep(i,n){
      if(v[i].S&&v[i].F.F<=l&&l<=v[i].F.S){
        r.PB(P(v[i].F.S-l,i));
      }
    }
    if(r.size()<k) continue;
    sort(all(r));
    reverse(all(r));
    rep(i,r.size()-k){
      v[r[i].S].S=false;
      ans.PB(r[i].S+1);
    }
  }

  sort(all(ans));

  cout<<ans.size()<<endl;
  rep(i,ans.size()){
    cout<<ans[i]<<' ';
  }
  cout<<endl;


}
