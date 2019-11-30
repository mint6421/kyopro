

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


int n;
int dp[3100][3100];
string s;

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n;
  cin>>n;
  cin>>s;
  rep(j,n) dp[0][j]=1;

  FOR(i,1,n){
    BIT<int> bit(n);
    rep(j,n-i+1) bit.add(j,dp[i-1][j]);
    rep(j,n-i){
      if(s[i-1]=='<') dp[i][j]=bit.sum(j);
      else dp[i][j]=bit.get(j,n-1);
    }
  }

  cout<<dp[n-1][0]<<endl;
}

