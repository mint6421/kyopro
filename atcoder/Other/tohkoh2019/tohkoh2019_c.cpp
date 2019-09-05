
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

  int n,x;
  cin>>n>>x;
  vi a(n);
  int res=0;
  rep(i,n){
    cin>>a[i];
    if(a[i]==-1) continue;
    res^=a[i];
  }

  rep(i,n){
    if(a[i]==-1&&(res^x)<=x){
      a[i]=res^x;
      res=x;
    }else if(a[i]==-1){
      int t=res^x;
      int j=1;
      while(j<=t) j*=2;
      j/=2;
      if(j<=x){
        a[i]=j;
        res=j^res;
      }
    }
  }

  if(res!=x){
    cout<<-1<<endl;
    return 0;
  }else{
    rep(i,n){
      cout<<a[i]<<' ';
    }
    cout<<endl;
  }


}
