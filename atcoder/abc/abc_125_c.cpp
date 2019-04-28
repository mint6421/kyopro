
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
void init(){
  cin.tie(0);
  ios::sync_with_stdio(false);
}


int n;
int a[110000];
int r[110000],l[110000];


int main(){
  cin>>n;
  rep(i,n){
    cin>>a[i];
  }

  r[0]=a[0];
  l[n-1]=a[n-1];
  FOR(i,1,n+1){
    r[i]=__gcd(r[i-1],a[i]);
  }
  rrep(i,n-2){
    l[i]=__gcd(l[i+1],a[i]);
  }

  int ans=max(r[n-2],l[1]);
/*
  rep(i,n){
    cout<<l[i]<<' '<<r[i]<<endl;
  }
*/

  FOR(i,1,n-1){
    ans=max(ans,__gcd(r[i-1],l[i+1]));
  }

  cout<<ans<<endl;
}
