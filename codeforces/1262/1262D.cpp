

#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX
#define INF LLONG_MAX
#define ll long long
#define ull unsigned long long
#define M (int)(1e9+7)
#define P pair<int,int>
#define FOR(i,m,n) for(int i=(int)m;i<(int)n;i++)
#define RFOR(i,m,n) for(int i=(int)m;i>=(int)n;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,n,0)
#define all(a) a.begin(),a.end()
const int vx[4] = {0,1,0,-1};
const int vy[4] = {1,0,-1,0};
#define F first
#define S second
#define PB push_back
#define EB emplace_back
#define int ll
#define vi vector<int>
#define IP pair<int,P>
#define PI pair<P,int>
#define PP pair<P,P>
#define Yes(f){cout<<(f?"Yes":"No")<<endl;}
#define YES(f){cout<<(f?"YES":"NO")<<endl;}
int Madd(int x,int y) {return (x+y)%M;}
int Msub(int x,int y) {return (x-y+M)%M;}
int Mmul(int x,int y) {return (x*y)%M;}



template< typename T >
struct BIT {
  vector< T > data;

  BIT(int sz) {
    data.assign(++sz, 0);
  }

  T sum(int k) {
    T ret = 0;
    for(++k; k > 0; k -= k & -k) ret=Madd(ret,data[k]);
    return (ret);
  }

  T get(int x,int y){

    return Msub(sum(y),sum(x));
  }

  void add(int k, T x) {
    for(++k; k < data.size(); k += k & -k) data[k]=Madd(data[k],x);
  }
};


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n;
  cin>>n;
  vector<P> a(n);
  vi aa(n);
  rep(i,n){
    cin>>a[i].F;
    aa[i]=a[i].F;
    a[i].S=-i;
  }

  sort(all(a));
  reverse(all(a));
  rep(i,n){
    a[i].S*=-1;
  }

  int m;
  cin>>m;

  vector<PI> q(m);
  rep(i,m){
    cin>>q[i].F.F>>q[i].F.S;
    q[i].F.S;
    q[i].S=i;
  }
  sort(all(q));
  BIT<int> bit(n+1);

  vi ans(m,0);
  int j=0;
  int i=0;
  while(i<m){
    if(q[i].F.F>j){
      bit.add(a[j].S,1);
      j++;
      continue;
    }
    int l=-1,r=n;
    while(r-l>1){
      int k=(l+r)/2;
      if(bit.sum(k)<q[i].F.S) l=k;
      else r=k;
    }
    //cout<<r<<endl;
    ans[q[i].S]=aa[r];
    i++;
    /*
    rep(i,n){
      cout<<bit.sum(i)<<' ';
    }
    cout<<endl;
    */
  }

  rep(i,m){
    cout<<ans[i]<<endl;
  }



}
