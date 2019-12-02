
#include<bits/stdc++.h>
using namespace std;
#define inf 1000000000
#define INF 1000000000000000
#define ll long long
#define ull unsigned long long
#define M (int)(1e9)
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

void init(){
  cin.tie(0);
  ios::sync_with_stdio(false);
}

vector<vector<int>> paskal(int n){
  vector<vector<int>> c(n+1,vector<int>(n+1,0));

  rep(i,n+1){
    rep(j,n+1){
      if(j>i) break;
      if(i==0||j==0) c[i][j]=1;
      else c[i][j]=c[i-1][j-1]+c[i-1][j];
      c[i][j]%=M;
    }
  }

  return c;
}

main(){
  ll n;
  int m;
  cin>>n>>m;

  int k=(n/1000)%m;

  vector<vector<int>> c=paskal(m);

  /*
  rep(i,10){
    rep(j,10){
      cout<<c[i][j]<<' ';
    }
    cout<<endl;
  }
  */

  cout<<c[m][k]<<endl;

}
