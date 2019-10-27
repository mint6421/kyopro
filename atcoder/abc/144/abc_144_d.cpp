
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
#define PI 3.141592653589793
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

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);


  double a,b,x;
  cin>>a>>b>>x;

  double s=a*a*b;
  if(s/2<x){
    double l=0,r=45;
    int t=1000;
    while(t--){
      double m=(l+r)/2;
      double p=M_PI;
      p*=m/180;
      double u=tan(p);
      
      u*=a*a*a;
      u/=2;
      if(u<s-x) l=m;
      else r=m;
    }
    cout<<l<<endl;
  }else{
    double l=0,r=45;
    int t=1000;
    while(t--){
      double m=(l+r)/2;
      double p=M_PI;
      p*=m/180;
      double u=tan(p);
      u*=b*b*a;
      u/=2;
      if(u>x) r=m;
      else l=m;
    }
    //cout<<l<<' '<<r<<endl;
    cout<<90-l<<endl;
  }
}
    
