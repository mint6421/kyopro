

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

  int t;
  cin>>t;
  while(t--){
    int n,m;
    cin>>n>>m;
    vi a(n);
    int sum=0;
    rep(i,n){
      cin>>a[i];
      sum+=2*a[i];
    }
    if(n>m){
      cout<<-1<<endl;
      continue;
    }

    
    vector<P> ans;
    rep(i,n){
      ans.PB(P(i,(i+1)%n));
    }

    vector<IP> v;
    rep(i,n){
      FOR(j,i+1,n){
        v.PB(IP(a[i]+a[j],P(i,j)));
      }
    }
    sort(all(ans));
    while(ans.size()<m){
      sum+=v[0].F;
      ans.PB(v[0].S);
    }

    cout<<sum<<endl;
    for(P p:ans){
      cout<<p.F+1<<' '<<p.S+1<<endl;
    }
  }


}
