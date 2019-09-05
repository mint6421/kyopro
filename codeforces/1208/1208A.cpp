
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


int f(int a,int b,int n){
  if(n==0) return a;
  if(n==1) return b;

  return (f(a,b,n-1)^f(a,b,n-2));
}


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int t;
  cin>>t;
  while(t--){
    int a,b,n;
    cin>>a>>b>>n;

    if(n%3==0) cout<<a<<endl;
    else if(n%3==1) cout<<b<<endl;
    else cout<<(a^b)<<endl;
    //cout<<f(a,b,n)<<endl;
  }
}
