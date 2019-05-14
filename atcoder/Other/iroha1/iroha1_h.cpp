
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

int f(int m){
  if(m==0) return 0;
  return m%10+f(m/10);
}


main(){
  int n;
  cin>>n;
  int m=f(n);
  if(n==m){
    cout<<10+n-1<<endl;
  }else{
    vector<int> res;
    while(m/10){
      res.PB(9);
      m-=9;
    }
    res.PB(m);
    int ans=0;
    rrep(i,res.size()-1){
      ans*=10;
      ans+=res[i];
    }
    if(ans==n){
      if(ans%9==0){
        int r=1;
        rep(_,res.size()-1) r*=10;
        ans-=r;
        ans+=10*r;
      }else{

        int r=1;
        rep(_,res.size()-2) r*=10;
        ans-=r;
        ans+=10*r;
      }
    }
    cout<<ans<<endl;
  }
}
