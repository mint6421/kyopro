
#include<bits/stdc++.h>
using namespace std;
#define inf 1000000000
#define INF 1000000000000000
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
void init(){
  cin.tie(0);
  ios::sync_with_stdio(false);
}


int n,m;
char s[510][510],t[510][510],a[510][510];


main(){

  cin>>n>>m;
  rep(i,n){
    cin>>a[i];
    rep(j,m){
      s[i][j]=a[i][j];
      t[i][j]=a[i][j];
    }
  }

  rep(i,n){
    rep(j,m-1){
      if(j==0)
        s[i][j]='#';
      if(i%2) continue;
      s[i][j]='#';
    }
  }

  rep(i,n){
    FOR(j,1,m){
      if(j==m-1)
        t[i][j]='#';
      if(i%2==0) continue;
      t[i][j]='#';
    }
  }

  rep(i,n){
    cout<<s[i]<<endl;
  }

  cout<<endl;

  rep(i,n){
    cout<<t[i]<<endl;
  }

}
