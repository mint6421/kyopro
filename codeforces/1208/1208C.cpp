
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


int a[1100][1100];

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin>>n;
  int m=n*n-1;

    /*
   0 15 1 14
   2 13 3 12
   4 11 5 10
   6  9 7  8
   */

  rep(j,n/4){
    rep(i,n){
      a[i][j*4]=(i+j*n)*4;
      a[i][j*4+1]=a[i][j*4]+1;
      a[i][j*4+2]=a[i][j*4]+2;
      a[i][j*4+3]=a[i][j*4]+3;
    }
  }

  rep(i,n){
    rep(j,n){
      cout<<a[i][j]<<' ';
    }
    cout<<endl;
  }

}

