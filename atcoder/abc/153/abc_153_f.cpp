

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



template< typename T >
struct Compress {
    vector< T > xs;

    Compress() = default;

    Compress(const vector< T > &vs) {
        add(vs);
    }

    Compress(const initializer_list< vector< T > > &vs) {
        for(auto &p : vs) add(p);
    }

    void add(const vector< T > &vs) {
        copy(begin(vs), end(vs), back_inserter(xs));
    }

    void add(const T &x) {
        xs.emplace_back(x);
    }

    void build() {
        sort(begin(xs), end(xs));
        xs.erase(unique(begin(xs), end(xs)), end(xs));
    }

    vector< int > get(const vector< T > &vs) const {
        vector< int > ret;
        transform(begin(vs), end(vs), back_inserter(ret), [&](const T &x) {
                return lower_bound(begin(xs), end(xs), x) - begin(xs);
                });
        return ret;
    }

    int get(const T &x) const {
        return lower_bound(begin(xs), end(xs), x) - begin(xs);
    }

    const T &operator[](int k) const {
        return xs[k];
    }
};



template< typename T >
struct BIT {
    vector< T > data;

    BIT(int sz) {
        data.assign(++sz, 0);
    }

    T sum(int k) {
        T ret = 0;
        for(++k; k > 0; k -= k & -k) ret+=data[k];
        return (ret);
    }

    T get(int x,int y){

        return sum(y)-sum(x);
    }

    void add(int k, T x) {
        for(++k; k < data.size(); k += k & -k) data[k]+=x;
    }
};

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<fixed<<setprecision(20);

    int n,d,a;
    cin>>n>>d>>a;

    vector<P> v(n);
    vi w(n);
    rep(i,n){
        cin>>v[i].F>>v[i].S;
        w[i]=v[i].F;
    }

    sort(all(v));

    Compress<int> com(w); 
    BIT<int> bit(n);
    com.build();

    int ans=0;

    rep(i,n){
        int it1=com.get(v[i].F);
        int h=v[i].S-bit.sum(it1);
        if(h<=0) continue;
        int c=(h+a-1)/a;

        //cout<<it1<<' '<<h<<' '<<c<<endl;
        //cout<<com.get(v[i].F+2*d)<<endl;
        ans+=c;
        bit.add(it1,a*c);
        bit.add(com.get(v[i].F+2*d+1),-a*c);
    }

    /*
    rep(i,n){
        cout<<bit.sum(i)<<endl;
    }
    */

    cout<<ans<<endl;

}
