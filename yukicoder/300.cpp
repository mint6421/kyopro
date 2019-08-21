
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


bool is_prime(int x){
  if(x<2) return false;
  for(int i=2;i*i<=x;i++){
    if(x%i==0) return false;
  }
  return true;
}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int x;
  cin>>x;
  int y=1,i=2;

  if(is_prime(x)){
    cout<<x<<endl;
    return 0;
  }

  while(x!=1){
    int res=0;
    while(x%i==0){
      res++;
      x/=i;
    }
    if(res){
      if(res%2) y*=i;
      if(is_prime(x)){
        y*=x;
        break;
      }
    }
    i++;
  }

  cout<<y<<endl;

  

}
