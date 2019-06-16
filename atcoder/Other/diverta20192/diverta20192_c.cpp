
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


int n;
vector<int> a,b;

main(){
  cin>>n;
  rep(i,n){
    int c;
    cin>>c;
    if(c>0) a.PB(c);
    else b.PB(c);
  }

  sort(all(a));
  sort(all(b));

  if(a.size()&&b.empty()){
    int res=0;

    int r=a[0];
    vector<P> ans;
    FOR(i,1,a.size()-1){
      ans.PB(P(r,a[i]));
      r-=a[i];
    }
    ans.PB(P(a[a.size()-1],r));
    r=a[a.size()-1]-r;
    cout<<r<<endl;
    rep(i,ans.size()){
      cout<<ans[i].F<<' '<<ans[i].S<<endl;
    }
  }else if(a.empty()&&b.size()){
    int res=0;
    reverse(all(b));
    int r=b[0];
    vector<P> ans;
    FOR(i,1,b.size()){
      ans.PB(P(r,b[i]));
      r-=b[i];
    }

    cout<<r<<endl;
    rep(i,ans.size()){
      cout<<ans[i].F<<' '<<ans[i].S<<endl;
    }
  }else{
    int r=a[a.size()-1];
    vector<P> ans;
    FOR(i,1,b.size()){
      ans.PB(P(r,b[i]));
      r-=b[i];
    }
    int s=b[0];
    rep(i,a.size()-1){
      ans.PB(P(s,a[i]));
      s-=a[i];
    }
    ans.PB(P(r,s));
    r-=s;
    cout<<r<<endl;
    rep(i,ans.size()){
      cout<<ans[i].F<<' '<<ans[i].S<<endl;
    }
  }

}
