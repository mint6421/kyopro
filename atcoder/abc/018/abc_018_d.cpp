
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

int n,m,p,q,r;
int x[2000],y[2000],z[2000];
int ans=0;


void solve(vi v){
  vi s(m,0);

  for(int t:v){
    rep(i,r){
      if(x[i]==t) s[y[i]]+=z[i];
    }
  }

  sort(all(s));
  reverse(all(s));
  int sum=0;
  rep(i,q){
    sum+=s[i];
  }

  ans=max(ans,sum);
}


void f(int k,vi v){

  if(v.size()==p){
    solve(v);
    return;
  }

  if(k==n) return;

  f(k+1,v);
  v.PB(k);
  f(k+1,v);
  v.erase(v.begin()+v.size()-1);
  
}


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  cin>>n>>m>>p>>q>>r;
  rep(i,r){
    cin>>x[i]>>y[i]>>z[i];
    x[i]--;y[i]--;
  }

  f(0,vi());

  cout<<ans<<endl;


}
