
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

  int n,m;
  cin>>n>>m;
  vector<P> v;
  rep(i,n){
    int a,b;
    cin>>a>>b;
    v.PB(P(a,b));
  }
  sort(all(v));
  
  priority_queue<int> q;

  int ans=0,j=0;
  FOR(i,1,m+1){
    while(j<n&&v[j].F<=i){
      q.push(v[j].S);
      j++;
    }
    if(q.empty()) continue;
    ans+=q.top();
    q.pop();
  }

  cout<<ans<<endl;


}
