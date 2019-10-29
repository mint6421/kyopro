
#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX
#define INF LLONG_MAX
#define ll long long
#define ull unsigned long long
#define M (int)(1e9+7)
#define P pair<int,int>
#define PLL pair<ll,ll>
#define FOR(i,m,n) for(int i=(int)m;i<(int)n;i++)
#define RFOR(i,m,n) for(int i=(int)m;i>=(int)n;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,n,0)
#define all(a) a.begin(),a.end()
#define IN(a,n) rep(i,n){ cin>>a[i]; }
const int vx[4] = {0,1,0,-1};
const int vy[4] = {1,0,-1,0};
#define PI 3.14159265
#define F first
#define S second
#define PB push_back
#define EB emplace_back
#define int ll
#define vi vector<int>
#define IP pair<int,P>
#define PP pair<P,P>
#define Yes(f){cout<<(f?"Yes":"No")<<endl;}
#define YES(f){cout<<(f?"YES":"NO")<<endl;}
#define PP pair<P,P>

bool intersect(PP a,PP b){
  int ta=(b.F.F-b.S.F)*(a.F.S-b.F.S)+(b.F.S-b.S.S)*(b.F.F-a.F.F);
  int tb=(b.F.F-b.S.F)*(a.S.S-b.F.S)+(b.F.S-b.S.S)*(b.F.F-a.S.F);
  int tc=(a.F.F-a.S.F)*(b.F.S-a.F.S)+(a.F.S-a.S.S)*(a.F.F-b.F.F);
  int td=(a.F.F-a.S.F)*(b.S.S-a.F.S)+(a.F.S-a.S.S)*(a.F.F-b.S.F);

  return (tc*td<0&&ta*tb<=0);
}


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);
  int ax,ay,bx,by;
  cin>>ax>>ay>>bx>>by;
  PP p=PP(P(ax,ay),P(bx,by));

  int n;
  cin>>n;
  vector<P> v;
  rep(i,n){
    int x,y;
    cin>>x>>y;
    v.PB(P(x,y));
  }

  vector<PP> res;
  rep(i,n){
    res.PB(PP(v[i],v[(i+1)%n]));
  }


  int ans=0;
  rep(i,n){
    ans+=f(res[i],p);
  }

  cout<<1+ans/2<<endl;
}
