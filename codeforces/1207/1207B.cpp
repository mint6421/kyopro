
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



signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int h,w;
  cin>>h>>w;
  int a[100][100];
  rep(i,h){
    rep(j,w){
      cin>>a[i][j];
    }
  }

  int b[100][100]={};

  vector<P> ans;

  rep(i,h-1){
    rep(j,w-1){
      if(a[i][j]&&a[i+1][j]&&a[i][j+1]&&a[i+1][j+1]){
        ans.PB(P(i,j));
        rep(y,2){
          rep(x,2){
            b[y+i][x+j]=1;
          }
        }
      }
    }
  }

  rep(i,h){
    rep(j,w){
      if(a[i][j]^b[i][j]){
        cout<<-1<<endl;
        return 0;
      }
    }
  }

  cout<<ans.size()<<endl;
  rep(i,ans.size()){
    cout<<ans[i].F+1<<' '<<ans[i].S+1<<endl;
  }


}
