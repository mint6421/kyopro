

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



struct Combinations {
  static int num;
  vi fact,factr,inv;

  Combinations(int num) {

    fact.assign(num+1,0);
    factr.assign(num+1,0);
    inv.assign(num+1,0);
    inv[1]=fact[0]=factr[0]=1;
    FOR(i,2,num+1) inv[i]=inv[M%i]*(M-M/i)%M;
    FOR(i,1,num+1) fact[i]=fact[i-1]*i%M,factr[i]=factr[i-1]*inv[i]%M;
  }


  int comb(int n,int c){
    if(c<0||c>n) return 0;
    return factr[c]*fact[n]%M*factr[n-c]%M;
  }

  int per(int n,int c){
    if(c<0||c>n) return 0;
    return fact[n]*factr[n-c]%M;
  }

  int hcomb(int n,int c){
    if(n==0&&c==0) return 1;
    return comb(n+c-1,c);
  }

};



template< typename T >
T bell_number(int n, int k) {
  if(n == 0) return 1;
  k = min(k, n);
  Combinations uku(k);
  T ret = 0;
  vector< T > pref(k + 1);
  pref[0] = 1;
  for(int i = 1; i <= k; i++) {
    if(i & 1) pref[i] = pref[i - 1] - uku.factr[i];
    else pref[i] = pref[i - 1] + uku.factr[i];
  }
  for(int i = 1; i <= k; i++) {
    ret += T(i).power(n) * uku.factr[i] * pref[k - i];
  }
  return ret;
}


Mint Combination7(int n,int k){
  return bell_number<Mint>(n,k);
}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n,k;
  cin>>n>>k;
  cout<<Combination7(n,k)<<endl;


}
