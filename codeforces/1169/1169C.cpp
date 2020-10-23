
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

int n,m;

bool f(int k,vector<int> v){
  vector<int> w(n);
  rep(i,n){
    w[i]=v[i];
  }
  if(w[0]+k>=m) w[0]=0;
  
  FOR(i,1,n){
    if(w[i]>w[i-1]&&w[i]+k>=w[i-1]+m) w[i]=w[i-1];
    else if(w[i]<w[i-1]&&w[i]+k>=w[i-1]) w[i]=w[i-1];
  }
  /*
  rep(i,n){
    cout<<w[i]<<' ';
  }
  cout<<endl;
  */

  FOR(i,1,n){
    if(w[i]<w[i-1]) return false;
  }

  return true;
}


main(){
  
  cin>>n>>m;
  vector<int> a(n);
  rep(i,n){
    cin>>a[i];
  }

  int l=0,r=m;
  while(r-l>1){
//    cout<<l<<' '<<r<<endl;
    int mm=(r+l)/2;
    if(f(mm,a)) r=mm;
    else l=mm+1;
  }

  cout<<(f(l,a)?l:r)<<endl;
}
