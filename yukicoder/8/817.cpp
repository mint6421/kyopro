
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

int n,k;
vector<P> v;

bool f(int m){
  int s=0;

  rep(i,n){
    if(v[i].S<=m) s+=v[i].S-v[i].F+1;
    else if(v[i].F<=m) s+=m-v[i].F;
  }

  return s>=k;
}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  cin>>n>>k;

  rep(i,n){
    int a,b;
    cin>>a>>b;
    v.PB(P(a,b));
  }

  int l=0,r=1e9;
  while(r-l>1){
    int m=(r+l)/2;
    if(f(m)) r=m;
    else l=m;
  }

  cout<<l<<endl;


}
