
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




double ans;
int ans1;
double n,m,a;
double b;

main(){
  cin>>n;
  b=(1+n)/2;

  double memo[510000];
  memo[1] = 1/n;

  for(int i=2;i<=n;i++){
    memo[i]=memo[i-1]*i*(n-i+1)/((i-1)*n);
  }

  
  for(int i=1;i<=n;i++){
    ans+=b*memo[i];
    b+=(1+n)/2;
    
  }

  printf("%.10lf\n",ans);
}
