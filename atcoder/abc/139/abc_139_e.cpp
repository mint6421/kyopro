
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

  rep(i,n){
    rep(j,n-1){
      cin>>a[i][j];
      a[i][j]--;
    }
  }

  bool flag=true;
  int count=0;
  int ans=0;
  int c[1100]={};
  int res[1100]={};
  while(count!=n){
    flag=false;
    rep(i,n){
      if(c[i]==n-1) continue;
      int b=a[i][c[i]];
      if(i==a[b][c[b]]){
        flag=true;
        int r=max(res[i]+1,res[b]+1);
        ans=max(ans,r);
        res[i]=r;
        res[b]=r;
        c[i]++;
        c[b]++;
        if(c[i]==n-1) count++;
        if(c[b]==n-1) count++;
        break;
      }
    }
    if(!flag){
      cout<<-1<<endl;
      return 0;
    }
  }

  cout<<ans<<endl;

}
