
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



struct BIT{
  vector<int> bit;
  int n;

  BIT(int m){
    n = m;
    bit.assign(2*n,0);
  }

  int sum(int i){
    int s = 0;
    while(i>0){
      s+=bit[i];
      i-=i&-i;
    }
    return s;
  }
  void add(int i,int x){
    while(i<=n){
      bit[i]+=x;
      i+=i&-i;
    }
  }
};

int s[200100],a[200100];

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);


  int n;
  cin>>n;
  BIT bit(n);
  rep(i,n){
    cin>>s[i];
  }
  rrep(i,n-1){

    int l=0,r=n;
    while(r-l>1){
      int m=(r+l)/2;
      int sum=m*(m+1)/2-bit.sum(m);
      if(sum>s[i]) r=m;
      else l=m;
    }
    a[i]=l+1;
    bit.add(a[i],a[i]);
  }

  rep(i,n){
    cout<<a[i]<<' ';
  }
  cout<<endl;


}
