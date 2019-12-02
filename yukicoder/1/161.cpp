
#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX
#define INF LLONG_MAX
#define ll long long
#define ull unsigned long long
#define M (int)(1e9+7)
//#define P pair<int,int>
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



signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int g,c,p;
  cin>>g>>c>>p;
  string s;
  cin>>s;
  int G=0,C=0,P=0;
  rep(i,s.size()){
    if(s[i]=='G') G++;
    if(s[i]=='C') C++;
    if(s[i]=='P') P++;
  }

  int ans=0;
  int r=min(g,C);
  ans+=3*r;
  g-=r;
  C-=r;
  r=min(c,P);
  ans+=3*r;
  c-=r;
  P-=r;
  r=min(p,G);
  ans+=3*r;
  p-=r;
  G-=r;

  r=min(g,G);
  ans+=r;
  r=min(c,C);
  ans+=r;
  r=min(p,P);
  ans+=r;

  cout<<ans<<endl;


}
