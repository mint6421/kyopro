
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

int ans;
int n;
vector<P> v;

void f(int p,int q){
  int res=0;
  bool b[100]={};

  rep(i,n){
    if(b[i]) continue;
    res++;
    int x=v[i].F,y=v[i].S;
    while(true){
      auto it = find(all(v),P(x+p,y+q));
      if(it==v.end()) break;
      b[it-v.begin()]=true;
      x+=p;
      y+=q;
    }
  }

  ans=min(ans,res);
}



signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  
  cin>>n;
  v.resize(n);
  ans=n;
  rep(i,n){
    cin>>v[i].F>>v[i].S;
  }
  sort(all(v));
  map<P,int> mp;
  rep(i,n){
    FOR(j,i+1,n){
      f(v[j].F-v[i].F,v[j].S-v[i].S);
    }
  }

  
  cout<<ans<<endl;


}
