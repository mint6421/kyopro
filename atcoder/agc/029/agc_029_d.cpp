
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


int h,w,n;

main(){
  cin>>w>>h>>n;
  vector<P> v;

  rep(i,n){
    int a,b;
    cin>>a>>b;
    v.PB(P(b,a));
  }

  
  sort(all(v));
  vector<int> res[210000];
  rep(i,n){
    res[v[i].F].PB(v[i].S);
  }

  int r=0;
  int ans=w;

 
  FOR(i,1,h+1){
    r++;
    while(find(all(res[i]),r)!=res[i].end()) r++;
    auto it = lower_bound(all(res[i]),r);
    //cout<<r<<' ';
    if(it==res[i].end()) continue;
    ans=min(ans,*it-1);
  }
  //cout<<endl;

  cout<<ans<<endl;
}

