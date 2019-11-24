

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
#define MPlus(x,y) {x=(x+y)%M;}
#define MSub(x,y) {x=(x-y+M)%M;}
#define MMul(x,y) {x=(x*y)%M;}


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int h,w,k,v;
  cin>>h>>w>>k>>v;
  int a[200][200];
  rep(i,h){
    rep(j,w){
      cin>>a[i][j];
      a[i][j]+=k;
    }
  }

  int s[200][200]={};
  rep(i,h){
    rep(j,w){
      s[i+1][j+1]=s[i][j+1]+s[i+1][j]-s[i][j]+a[i][j];
    }
  }

  int ans=0;
  rep(i,h+1){
    rep(j,w+1){
      FOR(y,i,h+1){
        FOR(x,j,w+1){
          int sum=s[y][x]-s[i][x]-s[y][j]+s[i][j];
          if(sum<=v) ans=max(ans,(y-i)*(x-j));
        }
      }
    }
  }

  cout<<ans<<endl;


}
