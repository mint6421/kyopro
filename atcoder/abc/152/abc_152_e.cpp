

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


template< typename T>
T power(T x,int k){
    T ret=1;
    while(k>0){
        if(k&1) (ret*=x);
        (x*=x); 
        k >>= 1;
    }
    return ret;
}



vector< bool > prime_table(int n) {
    vector< bool > prime(n + 1, true);
    if(n >= 0) prime[0] = false;
    if(n >= 1) prime[1] = false;
    for(int i = 2; i * i <= n; i++) {
        if(!prime[i]) continue;
        for(int j = i + i; j <= n; j += i) {
            prime[j] = false;
        }
    }
    return prime;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<fixed<<setprecision(20);

    int n;
    cin>>n;
    vi a(n);
    rep(i,n){
        cin>>a[i];
    }

    vector<bool> prime = prime_table(1000000);

    
    vector<Mint> m(n,1);
    for(int k=2;k<10000;k++){
        if(!prime[k]) continue;
        vi s(n,0);
        int sc=0;
        rep(i,n){
            while(a[i]%k==0){
                s[i]++;
                a[i]/=k;
                sc=max(sc,s[i]);
            }
        }
        rep(i,n){
            m[i]*=power<Mint>(k,sc-s[i]);
        }
    }

    Mint ans=0;
    

    set<int> st;
    rep(i,n){
        st.insert(a[i]);
    }


    for(int s:st){
        rep(i,n){
            if(a[i]%s)
                m[i]*=s;
        }
    }

    rep(i,n){
        ans+=m[i];
    }
    

    cout<<ans<<endl;



}
