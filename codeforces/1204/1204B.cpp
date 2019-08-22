
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

  int n,l,r;
  cin>>n>>l>>r;

  vector<int> a(n),b(n);

  a[0]=1;
  b[0]=1;
  int suma=0,sumb=1;
  rep(i,n-l+1){
    a[i]=1;
    suma+=1;

  }
  FOR(i,n-l+1,n){
    a[i]=a[i-1]*2;
    suma+=a[i];
  }
  FOR(i,1,r){
    b[i]=b[i-1]*2;
    sumb+=b[i];
  }
  FOR(i,r,n){
    b[i]=b[i-1];
    sumb+=b[i];
  }

  cout<<suma<<' '<<sumb<<endl;

}
