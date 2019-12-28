

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


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  double ans=0;
  double l1,r1,l2,r2,l3,r3;
  cin>>l1>>r1>>l2>>r2>>l3>>r3;

  for(double i=l1;i<=r1;i++){
    double s=1/(r1-l1+1);
    if(i>=r2||i>=r3) break;
    //cout<<s<<endl;
    ans+=s*((r2-max(l2,i+1)+1)/(r2-l2+1))*((r3-max(l3,i+1)+1)/(r3-l3+1));
  }

  cout<<ans<<endl;


}
