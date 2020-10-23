
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


int n,z;

main(){
  cin>>n>>z;
  vector<int> v(n);
  rep(i,n){
    cin>>v[i];
  }

  sort(all(v));
  int l=0,r=n/2+1;

  while(r-l>1){
    int m=(l+r)/2;
    bool flag=true;
    rep(i,m){
      flag &= (v[n-m+i]-v[i]>=z);
    }
    if(flag)
      l=m;
    else
      r=m;
  }

  cout<<l<<endl;
}
