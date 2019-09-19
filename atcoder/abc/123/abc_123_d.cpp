
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

int x,y,z,k;
int a[1100],b[1100],c[1100];

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  cin>>x>>y>>z>>k;
  rep(i,x){
    cin>>a[i];
  }
  rep(i,y){
    cin>>b[i];
  }
  rep(i,z){
    cin>>c[i];
  }

  vi ab;
  rep(i,x){
    rep(j,y){
      ab.PB(a[i]+b[j]);
    }
  }
  sort(all(ab));
  reverse(all(ab));

  vi abc;
  for(int i=0;i<x*y&&i<3001;i++){
    rep(j,z){
      abc.PB(ab[i]+c[j]);
    }
  }

  sort(all(abc));
  reverse(all(abc));

  rep(i,k){
    cout<<abc[i]<<endl;
  }

}
