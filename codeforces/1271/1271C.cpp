

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

  int n,sx,sy;
  cin>>n>>sx>>sy;
  vector<P> v(4,P(0,0));
  rep(i,4) v[i].S=i;

  rep(i,n){
    int x,y;
    cin>>x>>y;
    if(x>sx) v[1].F++;
    if(x<sx) v[3].F++;
    if(y>sy) v[0].F++;
    if(y<sy) v[2].F++;
  }

  sort(all(v));
  reverse(all(v));
  cout<<v[0].F<<endl;
  cout<<sx+vx[v[0].S]<<' '<<sy+vy[v[0].S]<<endl;


}
