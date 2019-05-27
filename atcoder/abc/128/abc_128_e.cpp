
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
#define PP pair<int,P>
void init(){
  cin.tie(0);
  ios::sync_with_stdio(false);
}


main(){
  int n,q;
  cin>>n>>q;
  vector<PP> v;
  rep(i,n){
    int a,b,c;
    cin>>a>>b>>c;
    v.PB(PP(c,P(a-c,b-c-1)));
  }
  sort(all(v));

  int i=0;
  vector<P> a;
  rep(_,q){
    int d;
    cin>>d;
    a.PB(P(d,i));
  }
  int ans[300000]={};
  int b[300000]={};
  rep(i,n){
    auto l=lower_bound(all(a),P(v[i].S.F,0));
    auto r=upper_bound(all(a),P(v[i].S.S,inf));
    int la=l-a.begin(),ra=r-a.begin();
//    cout<<la<<' '<<ra<<endl;
    FOR(j,la,ra){
      if(b[j]) j=b[j]-1;
      if(ans[j]) continue;
      ans[j]=v[i].F;
      b[j]=ra;
    }
    
  }

  rep(i,q){
    cout<<((!ans[i])?-1:ans[i])<<endl;
  }


}
