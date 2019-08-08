
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



signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n,k;
  cin>>n>>k;
  vector<P> v(k);
  rep(i,k){
    cin>>v[i].F>>v[i].S;
    v[i].F--;v[i].S--;
  }

  vi a(n);
  rep(i,n){
    cin>>a[i];
    a[i];
  }

  vi b(n);
  rep(i,n){
    b[i]=a[i];
  }
  rep(i,k){
    swap(b[v[i].F],b[v[i].S]);
  }

  rep(i,n){
    //cout<<b[i]<<' ';
  }
  //cout<<endl;


  vector<P> ans;
  rep(i,n){
    int l=i;
    FOR(j,i,n){
      //cout<<b[j]<<' '<<a[i]<<endl;
      if(b[j]==i+1) l=j;
    }
    //cout<<i<<' '<<l<<endl;
    while(l!=i){
      ans.PB(P(l-1,l));
      swap(b[l-1],b[l]);
      l--;
    }
  }

  rep(i,n){
    //cout<<b[i]<<' ';
  }
  //cout<<endl;

  cout<<ans.size()<<endl;
  rep(i,ans.size()){
    cout<<ans[i].F+1<<' '<<ans[i].S+1<<endl;
  }

  vi c(n);
  rep(i,n){
    c[i]=i+1;
  }


  /*
  rrep(i,ans.size()-1){
    swap(c[ans[i].F],c[ans[i].S]);
  }

  rrep(i,k-1){
    swap(c[v[i].F],c[v[i].S]);
  }

  rep(i,n){
    cout<<c[i]<<' ';
  }
  cout<<endl;
  
  */

}
