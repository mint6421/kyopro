
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


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int h,w;
  int a[510][510];

  cin>>h>>w;
  rep(i,h){
    rep(j,w){
      cin>>a[i][j];
    }
  }

  int i=0,j=0;
  vector<PP> ans;
 
  while(true){
    int ni=i,nj=j;
    if(i%2==0){
      if(nj==w-1) ni++;
      else nj++;
    }else{
      if(nj==0) ni++;
      else nj--;
    }
    //cout<<i<<' '<<j<<' '<<a[i][j]<<endl;
    if(!(0<=ni&&ni<h&&0<=nj&&nj<w)){
 
      break;
    }

    if(a[i][j]%2){
      ans.PB(PP(P(i+1,j+1),P(ni+1,nj+1)));
      a[i][j]--;
      a[ni][nj]++;
    }
    i=ni;
    j=nj;
  }


  cout<<ans.size()<<endl;
  rep(i,ans.size()){
    P x=ans[i].F,y=ans[i].S;
    cout<<x.F<<' '<<x.S<<' '<<y.F<<' '<<y.S<<endl;
  }
  


}
