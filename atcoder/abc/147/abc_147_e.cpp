

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

bitset<26000> bset[100][100];
int c[100][100];

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int h,w;
  cin>>h>>w;
  rep(i,h){
    rep(j,w){
      cin>>c[i][j];
    }
  }
  rep(i,h){
    rep(j,w){
      int b;
      cin>>b;
      c[i][j]-=b;
      c[i][j]=abs(c[i][j]);
    }
  }

  int bi=13000;
  bset[h-1][w][bi]=1;
  rrep(i,h-1){
    rrep(j,w-1){
      bset[i][j]|=(bset[i+1][j]<<c[i][j]);
      bset[i][j]|=(bset[i+1][j]>>c[i][j]);
      bset[i][j]|=(bset[i][j+1]<<c[i][j]);
      bset[i][j]|=(bset[i][j+1]>>c[i][j]);
      
    }
  }

  int ans=inf;
  rep(i,26000){
    if(bset[0][0][i]) ans=min(ans,abs(i-bi));
  }
  cout<<ans<<endl;


}
