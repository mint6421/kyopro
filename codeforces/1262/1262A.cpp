

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
#define MPlus(x,y) {x=(x+y)%M;}
#define MSub(x,y) {x=(x-y+M)%M;}
#define MMul(x,y) {x=(x*y)%M;}


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int q;
  cin>>q;
  while(q--){
    int n;
    cin>>n;
    vector<P> v(n);
    rep(i,n){
      cin>>v[i].F>>v[i].S;
    }
    int sl=0,sr=inf;
    int ok=0,ng=inf;
    while(ng-ok>1){
      int m=(ok+ng)/2;
      //cout<<m<<endl;
      bool flag=true;
      rep(i,n){
        if(m>v[i].S){
          flag=false;
        }
      }
      if(flag) ok=m;
      else ng=m;
    }
    sl=ok;
    
    ok=inf,ng=0;
    while(ok-ng>1){
      int m=(ok+ng)/2;
      bool flag=true;
      rep(i,n){
        if(!(sl<=v[i].S&&v[i].F<=m)){
          flag=false;
        }
      }
      if(flag) ok=m;
      else ng=m;
    }
    sr=ok;
    //cout<<sl<<' '<<sr<<endl;
    cout<<max(0LL,sr-sl)<<endl;

  }




}
