
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
  int n,k;
  cin>>n>>k;

  vector<P> v(n);
  rep(i,n){
    cin>>v[i].S>>v[i].F;
  }
  sort(all(v));
  reverse(all(v));
  priority_queue<int,vector<int>,greater<int>> q;

  int ans=-1;
  int sum=0;
  rep(i,n){
    sum+=v[i].S;
    q.push(v[i].S);
    ans=max(ans,sum*v[i].F);
    if(i>=k-1){
      sum-=q.top();
      q.pop();
    }
  }

  cout<<ans<<endl;
}
