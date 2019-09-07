
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
  vi a(n);
  rep(i,n){
    cin>>a[i];
  }
  int bit[1000]={};
  rep(i,n){
    int x=a[i];
    int j=1,c=0;
    while(j<=x){
      bit[c]+=!!(x&j);
      j<<=1;
      c++;
    }
    //cout<<x<<endl;
  }

  int x=1,c=0;
  while(x<=k){
    x<<=1;
    c++;
  }
  x>>=1;
  c--;
  int res=0;
  rrep(i,c){
    if(n-bit[i]>bit[i]&&res+x<=k){
      res+=x;
    }
    x>>=1;
  }

  int ans=0;
  rep(i,n){
    ans+=res^a[i];
  }

  cout<<ans<<endl;

}
