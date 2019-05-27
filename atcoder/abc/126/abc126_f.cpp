
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


main(){
  int m,k;
  cin>>m>>k;
  int n=(1<<m);

  if(m==0&&k==0){
    cout<<0<<' '<<0<<endl;
    return 0;
  }

  bool b[(1<<m)]={};
  vector<P> v;
  rep(i,n){
    if(b[i]) continue;
    int a=i^k;
    if(a>=n){
      cout<<-1<<endl;
      return 0;
    }
    
    b[i]=true;
    b[a]=true;
    v.PB(P(i,a));
//    cout<<i<<' '<<a<<endl;
  }


 

  if(v.size()%2){
    cout<<-1<<endl;
    return 0;
  }

  if(v[0].F==v[0].S){
    rep(i,v.size()){
      cout<<v[i].F<<' '<<v[i].S<<' ';
    }
    cout<<endl;
  }

  else{
    for(int i=0;i<v.size();i+=2){
      cout<<v[i].F<<' '<<v[i+1].S<<' '<<v[i+1].F<<' '<<v[i].F<<' '<<v[i].S<<' '<<v[i+1].F<<' '<<v[i+1].S<<' '<<v[i].S<<' ';
    }
    cout<<endl;
  }

}

