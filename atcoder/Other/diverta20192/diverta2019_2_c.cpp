
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
#define Yes(f){cout<<(f?"Yes":"No")<<endl;}
#define YES(f){cout<<(f?"YES":"NO")<<endl;}


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n;
  cin>>n;
  priority_queue<int,vi,greater<int>> plus;
  priority_queue<int> minus;

  vector<P> res;

  rep(i,n){
    int a;
    cin>>a;
    if(a>0) plus.push(a);
    else minus.push(a);
  }

  if(minus.empty()){
    int s=plus.top(); plus.pop();
    int t=plus.top(); plus.pop();
    if(n==2){
      cout<<t-s<<endl;
      cout<<t<<' '<<s<<endl;
      return 0;
    }
    res.PB(P(t,s));
    minus.push(t-s);
  }

  if(plus.empty()){
    int s=minus.top(); minus.pop();
    int t=minus.top(); minus.pop();
    if(n==2){
      cout<<t-s<<endl;
      cout<<t<<' '<<s<<endl;
      return 0;
    }
    res.PB(P(t,s));
    plus.push(t-s);
  }

  while(plus.size()>1){
    int s=plus.top(); plus.pop();
    int t=minus.top(); minus.pop();
    res.PB(P(t,s));
    minus.push(t-s);
  }

  int ans=plus.top();

  while(minus.size()){
    int s=minus.top(); minus.pop();
    res.PB(P(ans,s));
    ans-=s;
  }

  cout<<ans<<endl;
  for(P p:res){
    cout<<p.F<<' '<<p.S<<endl;
  }

}
