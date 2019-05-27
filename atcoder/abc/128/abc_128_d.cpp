
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

int n,k;
int ans=0;
vector<int> v;

void f(int m){
  int del=k-m;
 
  rep(i,m+1){
    int l=i,r=m-i;
    
    vector<int> a;
    rep(j,l){
      a.PB(v[j]);
    }
    for(int j=n-1;j>n-1-r;j--){
      a.PB(v[j]);
    }
    
    int res=0;
    sort(all(a));
    rep(j,m){
      res+=a[j];
    }
    ans=max(res,ans);
    rep(j,del){
      if(j>=a.size()) continue;
      res-=a[j];
      ans=max(res,ans);
    }
  }
}


main(){
  cin>>n>>k;
  v.resize(n);
  rep(i,n){
    cin>>v[i];
  }

  FOR(i,1,k+1){
    if(i>n) break;
    f(i);
  }

  cout<<ans<<endl;
}
