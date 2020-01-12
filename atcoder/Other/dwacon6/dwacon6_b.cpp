

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



struct Mint {
  int x;

  Mint() : x(0) {}

  Mint(int y) : x(y >= 0 ? y % M : (M - (-y) % M) % M) {}

  Mint &operator+=(const Mint &p) {
    if((x += p.x) >= M) x -= M;
    return *this;
  }

  Mint &operator-=(const Mint &p) {
    if((x += M - p.x) >= M) x -= M;
    return *this;
  }

  Mint &operator*=(const Mint &p) {
    x = (int) (1LL * x * p.x % M);
    return *this;
  }

  Mint &operator/=(const Mint &p) {
    *this *= p.inverse();
    return *this;
  }

  Mint operator-() const { return Mint(-x); }

  Mint operator+(const Mint &p) const { return Mint(*this) += p; }

  Mint operator-(const Mint &p) const { return Mint(*this) -= p; }

  Mint operator*(const Mint &p) const { return Mint(*this) *= p; }

  Mint operator/(const Mint &p) const { return Mint(*this) /= p; }

  bool operator==(const Mint &p) const { return x == p.x; }

  bool operator!=(const Mint &p) const { return x != p.x; }

  Mint inverse() const {
    int a = x, b = M, u = 1, v = 0, t;
    while(b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return Mint(u);
  }

  Mint power(int n) const {
    Mint ret(1), mul(x);
    while(n > 0) {
      if(n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  friend ostream &operator<<(ostream &os, const Mint &p) {
    return os << p.x;
  }

  friend istream &operator>>(istream &is, Mint &a) {
    int t;
    is >> t;
    a = Mint(t);
    return (is);
  }


};
using mint = Mint;

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n;
  cin>>n;
  vector<Mint> v(n);
  rep(i,n){
    cin>>v[i];
  }

  Mint mul=1;
  FOR(i,1,n){
    mul*=i;
  }
  

  Mint ans=0;
  Mint m=mul;
  rep(i,n-1){
    Mint k=i+2;
    ans+=(v[i+1]-v[i])*mul;
    //cout<<ans<<endl;
    mul+=m/k;
  }

  cout<<ans<<endl;


}
