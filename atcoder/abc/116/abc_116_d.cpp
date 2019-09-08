
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

  int k,n;
  cin>>n>>k;
  priority_queue<P> q1;
  priority_queue<P,vector<P>,greater<P>> q2;

  rep(i,n){
    int t,d;
    cin>>t>>d;
    q1.push(P(d,t));
  }

  int ans=0,sum=0;
  vi v(n+1,0);
  int x=0;
  rep(i,k){
    P p=q1.top(); q1.pop();
    sum+=p.F;
    if(v[p.S]==0) x++;
    v[p.S]++;
    if(v[p.S]>1) q2.push(p);
  }
  ans=sum+x*x;

  rep(i,n-k){
    P p=q1.top();q1.pop();
    if(v[p.S]||q2.empty()) continue;
    P p2=q2.top();q2.pop();
    sum-=p2.F;
    sum+=p.F;
    v[p.S]++;
    x++;
    ans=max(ans,sum+x*x);
  }


  cout<<ans<<endl;

 

}
