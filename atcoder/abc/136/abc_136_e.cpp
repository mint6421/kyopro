
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


int n,k;
int asum=0;
int a[1000],b[1000];


bool f(int d){
  /*
  rep(i,n){
    cout<<a[i]<<' ';
  }
  cout<<endl;
  */
  rep(i,n){
    b[i]=a[i]%d;
  }
  /*
  rep(i,n){
    cout<<b[i]<<' ';
  }
  cout<<endl;
  */
  sort(b,b+n);
  
  int res=INF;
  int l=0,r=0;
  rep(i,n){
    r+=d-b[i];
  }

  rep(i,n){
    l+=b[i];
    r-=d-b[i];
    if(l==r) res=min(res,l);
  }

  return res<=k;
}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin>>n>>k;
  
  rep(i,n){
    cin>>a[i];
    asum+=a[i];
  }

  if(k==0){
    int ans=a[0];
    rep(i,n){
      ans=__gcd(ans,a[i]);
    }
    cout<<ans<<endl;
    return 0;
  }

  vi res;
  for(int i=1;i*i<=asum;i++){
    if(asum%i) continue;
    res.PB(asum/i);
    res.PB(i);
  }
  sort(all(res));
  reverse(all(res));

  rep(i,res.size()){
   
    if(f(res[i])){
      cout<<res[i]<<endl;
      break;
    }
  }

  

}
