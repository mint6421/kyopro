

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

  int a,b;
  cin>>a>>b;

  int s=0,i=1;
  int ax=-1,ay=-1,bx=-1,by=-1;
  while(ax==-1||bx==-1){
    if(s+i>=a&&ax==-1){
      int j=1;
      while(s+j<a) j++;
      ax=i+1-j;
      ay=j;
    }
    if(s+i>=b&&bx==-1){
      int j=1;
      while(s+j<b) j++;
      bx=i+1-j;
      by=j;
    }
    s+=i;
    i++;
  }

  int x=ax+bx,y=ay+by;
  //cout<<ax<<' '<<ay<<' '<<bx<<' '<<by<<endl;
  //cout<<x<<' '<<y<<endl;
  cout<<(x+y-1)*(x+y-2)/2+y<<endl;
}
