

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
struct CumulativeSum2D {
  vector< vector< T > > data;

  CumulativeSum2D(int W, int H) : data(W+1,vector<T>(H + 1, 0)) {}

  CumulativeSum2D(vector<vector<T>> v) : data(v.size()+1,vector<T>(v[0].size()+1,0)){rep(i,v.size())rep(j,v[i].size())add(i,j,v[i][j]); build();}

  void add(int x, int y, T z) {
    ++x, ++y;
    if(x >= data.size() || y >= data[0].size()) return;
    data[x][y] += z;
  }

  void build() {
    for(int i = 0; i < data.size()-1; i++) {
      for(int j = 0; j < data[i].size()-1; j++) {
        data[i+1][j+1] += data[i][j+1]+data[i+1][j]-data[i][j];
      }
    }
  }

  T query(int sx, int sy, int gx, int gy) {
    return (data[gx][gy] - data[sx][gy] - data[gx][sy] + data[sx][sy]);
  }

  T get(int x,int y){
    return data[x][y];
  }

};

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n;
  cin>>n;
  CumulativeSum2D<int> s(1010,1010);

  while(n--){
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    s.add(x2,y2,1);
    s.add(x1,y2,-1);
    s.add(x2,y1,-1);
    s.add(x1,y1,1);
  }
  s.build();

  int ans=0;
  rep(i,1010){
    rep(j,1010){
      ans=max(ans,s.get(i,j));
    }
  }

  cout<<ans<<endl;



}
