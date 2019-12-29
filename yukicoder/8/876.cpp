

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

  void add(int k, T x) {
    for(++k; k < data.size(); k += k & -k) data[k]=Madd(data[k],x);
  }
};

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n,q;
  cin>>n>>q;
  BIT<int> sum(2*n),num(2*n);
  rep(i,n){
    int x;
    cin>>x;
    sum.add(i+1,x);
    sum.add(i+2,-x);
  }

  rep(i,n-1){
    if(sum.sum(i+1)!=sum.sum(i+2)) num.add(i+1,1);
  }

  while(q--){
    int t,l,r;
    cin>>t>>l>>r;
    
    if(t==1){
      int x;
      cin>>x;
      if(sum.sum(l-1)!=sum.sum(l)) num.add(l-1,-1);
      if(sum.sum(r)!=sum.sum(r+1)) num.add(r,-1);
      sum.add(l,x);
      sum.add(r+1,-x);
      if(sum.sum(l-1)!=sum.sum(l)) num.add(l-1,1);
      if(sum.sum(r)!=sum.sum(r+1)) num.add(r,1);
    }else{
      cout<<1+num.sum(r-1)-num.sum(l-1)<<endl;
    }
  }

}
