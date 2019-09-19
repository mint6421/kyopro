
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
#define IP pair<int,P>
#define PP pair<P,P>


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n,k;
  string s;
  cin>>n>>k;
  cin>>s;
  vector<P> v;
  int t=0;
  rep(i,n){
    int j=i;
    v.PB(P(t,s[i]));
    while(j<n&&s[i]==s[j]) j++;
    t+=j-i;
    i=j-1;
  }
  v.PB(P(t,0));

  int ans=0;
  rep(i,v.size()){
    int m=v.size()-1;
    int ij=i+k*2+(v[i].S=='1');
    int j=min(m,ij);
    ans=max(ans,v[j].F-v[i].F);
  }

  cout<<ans<<endl;



}
