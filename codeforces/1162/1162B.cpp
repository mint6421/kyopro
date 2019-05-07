
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

int a[100][100];
int b[100][100];

main(){
  cin>>n>>m;
  rep(i,n){
    rep(j,m){
      cin>>a[i][j];
    }
  }

  rep(i,n){
    rep(j,m){
      int c;
      cin>>c;
      if(c>a[i][j]){
        b[i][j]=c;
      }else{
        b[i][j]=a[i][j];
        a[i][j]=c;
      }
    }
  }

 
  rep(i,n){
    rep(j,m-1){
      if(b[i][j]>=b[i][j+1]||a[i][j]>=a[i][j+1]){
        cout<<"Impossible"<<endl;
        return 0;
      }
    }
  }

  rep(i,n-1){
    rep(j,m){
      if(b[i][j]>=b[i+1][j]||a[i][j]>=a[i+1][j]){
        cout<<"Impossible"<<endl;
        return 0;
      }
    }
  }

  cout<<"Possible"<<endl;
}
