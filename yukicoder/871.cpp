

#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX
#define INF LLONG_MAX
#define ll long long
#define ull unsigned long long
#define M (int)(1e9+7)
#define P pair<int,int>
#define FOR(i,m,n) for(int i=(int)m;i<(int)n;i++)
#define RFOR(i,m,n) for(int i=(int)m;i>=(int)n;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,n,0)
#define all(a) a.begin(),a.end()
const int vx[4] = {0,1,0,-1};
const int vy[4] = {1,0,-1,0};
#define F first
#define S second
#define PB push_back
#define EB emplace_back
#define int ll
#define vi vector<int>
#define IP pair<int,P>
#define PI pair<P,int>
#define PP pair<P,P>
#define Yes(f){cout<<(f?"Yes":"No")<<endl;}
#define YES(f){cout<<(f?"YES":"NO")<<endl;}
#define MPlus(x,y) {x=(x+y)%M;}
#define MSub(x,y) {x=(x-y+M)%M;}
#define MMul(x,y) {x=(x*y)%M;}


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n,k;
  cin>>n>>k;
  vi x(n);
  vi a(n);
  rep(i,n){
    cin>>x[i];
  }
  rep(i,n){
    cin>>a[i];
  }

  bool b[n]={};
  queue<int> q;
  b[k-1]=true;
  q.push(k-1);
  while(q.size()){
    int p=q.front(); q.pop();
    int l=lower_bound(all(x),x[p]-a[p])-x.begin();
    int r=upper_bound(all(x),x[p]+a[p])-x.begin();
    cout<<l<<' '<<r<<endl;
    r--;
    while(!b[l]){
      q.push(l);
      b[l]=true;
      l++;
    }
    while(!b[r]){
      q.push(r);
      b[r]=true;
      r--;
    }
  }

  int ans=0;
  rep(i,n){
    ans+=b[i];
  }

  cout<<ans<<endl;



}
