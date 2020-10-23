
#include<bits/stdc++.h>
using namespace std;
#define inf 1000000000
#define INF 1000000000000000
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
#define s set<int>
void init(){
  cin.tie(0);
  ios::sync_with_stdio(false);
}


map<P,s> mp;
int n;
int x[1100],y[1100];

main(){
  cin>>n;
  rep(i,n){
   cin>>x[i]>>y[i];
  }

  int t=0,res=0;
  rep(i,n){
    FOR(j,i+1,n){
      int x1=x[i],y1=y[i],x2=x[j],y2=y[j];
      int a=y1-y2,b=x1-x2;
      int d=__gcd(a,b);
      a/=d; b/=d;

      if(a<0||(a==0&&b<0)){
        a=-a;
        b=-b;
      }

      P p(a,b);
      int c=a*x1-b*y1;
      if(!mp[p].count(c)){
        t++;
        mp[p].insert(c);
        res+=t-mp[p].size();
      }
   }
  }

  cout<<res<<endl;
}
