

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



template< class T >
struct CumulativeSum {
  vector< T > data;

  CumulativeSum(int sz) : data(sz, 0) {};

  CumulativeSum(vector< T> v) : data(v.size()+1,0) {rep(i,v.size()) add(i+1,v[i]); build();};

  void add(int k, T x) {
    k++;
    if(k<0 || k>= data.size()) return;
    data[k] += x;
  }

  void build() {
    for(int i = 1; i < data.size(); i++) {
      data[i] += data[i - 1];
    }
  }

  T query(int l,int r) {  // [l,r)
    if(l < 0) return (0);
    return (data[min(r,(int)data.size()-1)]-data[min(l,(int)data.size()-1)]);
  }

  T operator[](const int &k) const {
    return data[k];
  }

};



signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n,t;
  cin>>n>>t;
  CumulativeSum<int> s(t+2);
  rep(i,n){
    int l,r;
    cin>>l>>r;
    s.add(l,1);
    s.add(r,-1);  
    
    /*
    rep(j,t+1){
      cout<<s[j]<<' ';
    }
    cout<<endl;
    */
    
  }
  s.build();

  /*
  rep(i,t+1){
    cout<<s[i]<<' ';
  }
  cout<<endl;
  */

  int ans=0;
  rep(i,t+1){
    ans=max(ans,s[i]);
  }

  cout<<ans<<endl;


}
