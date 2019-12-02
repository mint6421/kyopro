
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


bool is_prime(int x){
  if(x<2) return false;
  for(int i=2;i*i<=x;i++){
    if(x%i==0) return false;
  }
  return true;
}


int v[8000010];

main(){
  int n,d;
  cin>>n>>d; 


  FOR(i,1,n+1){
    FOR(j,1,n+1){
      v[i*i+j*j]++;
    }
  }
  

  int ans=0;
  FOR(i,1,n+1){
    FOR(j,1,n+1){
      int res=i*i-j*j+d;
      if(res<0||res>2*n*n) continue;
      ans+=v[res];
    }
  }

  cout<<ans<<endl;
}
