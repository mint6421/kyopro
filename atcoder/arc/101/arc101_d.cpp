
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
  int sum(int a,int b){
    
    return sum(b-1)-sum(a-1);
  }
  void add(int i,int x){
    while(i<=n){

      bit[i]+=x;
      i+=i&-i;
    }
  }
};



main(){
  int n;
  cin>>n;
  vector<int> a(n);
  rep(i,n){
    cin>>a[i];
  }

  int l=0,r=1<<30;
  while(r-l>1){
    int m=(r+l)/2;
    
    BIT bit(n+n+1);
    int num=0;
    int sum=0;
    bit.add(sum+n+1,1);
    rep(i,n){
      int c=(a[i]<=m)? 1:-1;
      sum+=c;
      num+=bit.sum(1,sum+n+1);
      bit.add(sum+n+1,1);
    }
    if(num>(n+1)*n/2/2) r=m;
    else l=m;
  }

  cout<<r<<endl;
}
