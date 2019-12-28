

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

  int q;
  cin>>q;
  while(q--){
    int n,m;
    cin>>n>>m;
    vi a(n);
    rep(i,n){
      cin>>a[i];
    }
    vi b(m);
    rep(i,m){
      cin>>b[i];
    }

    vi it(n+1);
    BIT<int> bit(n+10);
    rep(i,n){
      it[a[i]]=i;
      bit.add(i,1);
    }

    int ans=m;
    set<int> st;
    rep(i,m){
      auto itr=st.lower_bound(it[b[i]]);
      if(itr==st.end()){
        ans+=2*(bit.sum(it[b[i]]-1));
        //cout<<' '<<ans<<endl;
      }
      bit.add(it[b[i]],-1);
      st.insert(it[b[i]]);

    }

    cout<<ans<<endl;
  }




}
