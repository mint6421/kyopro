

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

  int n;
  cin>>n;
  priority_queue<P,vector<P>,greater<P>> q1; 
  priority_queue<P> q2;
  rep(i,n){
    int a,b;
    cin>>a>>b;
    if(a<b) q1.push(P(a,b));
    else q2.push(P(b,a));
  }

  int ans=0;
  int sum=0;
  while(q1.size()){
    P p=q1.top(); q1.pop();
    //cout<<p.F<<' '<<p.S<<endl;
    sum+=p.F;
    ans=max(ans,sum);
    sum-=p.S;
  }

  while(q2.size()){
    P p=q2.top(); q2.pop();
    sum+=p.S;
    ans=max(ans,sum);
    sum-=p.F;
  }

  cout<<ans<<endl;
}
