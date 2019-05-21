
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



ll power(ll x,ll k){
  ll ret=1;
  while(k>0){
    if(k&1) (ret*=x) %= M;
    (x*=x) %= M;
    k >>= 1;
  }
  
  return ret;
}


main(){
  int n;
  vector<int> ans;
  cin>>n;
  for(int i=0;i<n;i+=5){
    int c=0,sum=0;
    vector<int> v;
    rep(j,n){
      if(i<=j&&j<i+5){
       
        int r=power(5,c);
        v.PB(r);
        sum+=r;
        c++;
      }
      else{
        v.PB(0);
      }
    }
    cout<<'?';
    rep(j,n){
      cout<<' '<<v[j];
    }
    cout<<endl;
    int a;
    cin>>a;
    a-=8*sum;
    rep(j,c){
      ans.PB(a%5==1||a%5==3);
      a/=5;
    }
  }

  cout<<'!';
  rep(i,n){
    cout<<' '<<ans[i];
  }
  cout<<endl;

}
