

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

  int n;
  cin>>n;
  int d[110][110]={};
  rep(i,n){
    rep(j,n){
      d[i][j]=inf;
    }
  }
  rep(i,n){
    string s;
    cin>>s;
    rep(j,n){
      if(i==j) d[i][j]=0;
      if(s[j]=='1'){
        d[i][j]=1;
      }
    }
  }

  int m;
  cin>>m;
  vi a(m);
  rep(i,m){
    cin>>a[i];
  }



  rep(k,n){
    rep(i,n){
      rep(j,n){
        if(i==j||j==k||k==i) continue;
        if(d[i][j]>d[i][k]+d[k][j]){
          d[i][j]=d[i][k]+d[k][j];
        }
      }
    }
  }

  vi ans;
  ans.PB(a[0]-1);
  int t=a[0]-1,k=0;
  FOR(i,1,m){
    //cout<<a[i]-1<<' '<<t<<' '<<d[t][a[i]-1]<<' '<<i-k<<endl;
    if(d[t][a[i]-1]<i-k){
      ans.PB(a[i-1]-1);
      t=a[i-1]-1;
      k=i-1;
    }
  }

  ans.PB(a[m-1]-1);

  cout<<ans.size()<<endl;
  rep(i,ans.size()){
    cout<<ans[i]+1<<' ';
  }
  cout<<endl;


}
