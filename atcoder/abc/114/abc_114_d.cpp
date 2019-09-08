
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


int c[1000];
int d[1000];

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin>>n;
  
  FOR(i,1,n+1){
    int m=i;
    int j=2;
    while(m!=1){
      while(m%j==0){
        c[j]++;
        m/=j;
      }
      j++;
    }
  }

  rep(i,100){
    d[c[i]]++;
  }
  /*
  rep(i,10){
    cout<<c[i]<<endl;
  }
  */

  rrep(i,100){
    d[i]+=d[i+1];
  }

  /*
  rep(i,10){
    cout<<d[i]<<endl;
  }
  */
  

  int ans=0;
  ans+=d[74];
  ans+=d[24]*(d[2]-1);
  ans+=d[4]*(d[4]-1)/2*(d[2]-2);
  ans+=d[14]*(d[4]-1);

  cout<<ans<<endl;

}
