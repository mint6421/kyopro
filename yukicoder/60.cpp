
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

int c[1100][1100];

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n,k;
  cin>>n>>k;
  vi x(n),y(n),hp(n);
  rep(i,n){
    cin>>x[i]>>y[i]>>hp[i];
    x[i]+=500;
    y[i]+=500;
  }

  rep(i,k){
    int ax,ay,w,h,d;
    cin>>ax>>ay>>w>>h>>d;
    ax+=500;
    ay+=500;
    
    c[ay][ax]+=d;
    c[ay][min(1010LL,ax+w+1)]-=d;
    c[min(1010LL,ay+h+1)][ax]-=d;
    c[min(1010LL,ay+h+1)][min(1010LL,ax+w+1)]+=d;
  }

  rep(i,1000){
    rep(j,1000){
      c[i][j+1]+=c[i][j];
    }
  }

  rep(j,1010){
    rep(i,1010){
      c[i+1][j]+=c[i][j];
    }
  }

  int ans=0;
  rep(i,n){
    ans+=max(0LL,hp[i]-c[y[i]][x[i]]);
  }

  cout<<ans<<endl;

}
