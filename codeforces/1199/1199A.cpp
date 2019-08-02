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
 
int a[110000];
bitset<110000> b;
 
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
 
  int n,x,y;
  cin>>n>>x>>y;
 
  
  rep(i,n){
    cin>>a[i];
  }
 
 
 
  rep(i,n){
    bool f=true;
    FOR(j,i-x,i){
      if(j<0) continue;
      if(a[i]>a[j]){
        f=false;
        break;
      }
    }
    b[i]=f;
  }
 
 
  rep(i,n){
    bool f=true;
    if(!b[i]) continue;
    FOR(j,i+1,i+y+1){
      if(j>=n) continue;
      if(a[i]>a[j]){
        f=false;
        break;
      }
    }
    if(f){
      cout<<i+1<<endl;
      return 0;
    }
  }
 
 
 
 
 
}
