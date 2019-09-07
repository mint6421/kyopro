
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
#define PP pair<int,P>


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin>>n;
  int a[310][310];

  rep(i,n){
    rep(j,n){
      cin>>a[i][j];
    }
  }

  bool d[310][310]={};

  rep(k,n){
    rep(i,n){
      rep(j,n){
        if(i==j||j==k||k==i) continue;
        if(a[i][k]+a[k][j]<a[i][j]){
          cout<<-1<<endl;
          return 0;
        }else if(a[i][k]+a[k][j]==a[i][j]){
          //cout<<sum<<' '<<' '<<i<<' '<<j<<' '<<k<<' '<<a[i][j]<<endl;
          d[i][j]=true;
        }
      }
    }
  }

  int sum=0;

  rep(i,n){
    rep(j,n){
      if(!d[i][j]&&i!=j) sum+=a[i][j];
    }
  }

  cout<<sum/2<<endl;

}
