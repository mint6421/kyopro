
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
#define IP pair<int,P>
#define PP pair<P,P>

int n;
int a[1100][1100];

bool f(int k){
  vi res;
  res.PB(k);
  FOR(i,1,n){
    if(a[0][i]%k) return false;
    res.PB(a[0][i]/k);
  }

  

  rep(i,n){
    FOR(j,i+1,n){
      //cout<<res[i]<<' '<<res[j]<<' '<<a[i][j]<<endl;
      if(res[i]*res[j]!=a[i][j]) return false;
    }
  }
  //cout<<k<<endl;

  return true;
}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  cin>>n;
  rep(i,n){
    rep(j,n){
      cin>>a[i][j];
    }
  }

  vi res;
  int m=a[0][1];
  for(int i=1;i*i<=m;i++){
    if(m%i==0){
      if(f(i)){
        rep(j,n){
          if(j==0) cout<<i<<' ';
          else cout<<a[0][j]/i<<' ';
        }
        cout<<endl;
        return 0;
      }
      
      if(f(m/i)){
        i=m/i;
        rep(j,n){
          if(j==0) cout<<i<<' ';
          else cout<<a[0][j]/i<<' ';
        }
        cout<<endl;
        return 0;
      }
      
    }
  }


}
