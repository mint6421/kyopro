

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


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int c[3][3];
  cin>>c[0][0]>>c[0][1]>>c[1][1];

  rep(i,1000){
    c[0][2]=i-c[0][0]-c[0][1];
    c[2][1]=i-c[0][1]-c[1][1];
    c[2][0]=i-c[0][2]-c[1][1];
    c[2][2]=i-c[0][0]-c[1][1];
    c[1][0]=i-c[0][0]-c[2][0];
    c[1][2]=i-c[0][2]-c[2][2];
    if(i==c[1][0]+c[1][1]+c[1][2]){
      rep(i,3){
        rep(j,3){
          if(j) cout<<" ";
          cout<<c[i][j];
        }
        cout<<endl;
      }
      return 0;
    }
  }


}
