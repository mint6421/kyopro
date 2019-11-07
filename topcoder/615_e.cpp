
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
#define F first
#define S second
#define PB push_back
#define EB emplace_back
//#define int ll
#define vi vector<int>
#define IP pair<int,P>
#define PI pair<P,int>
#define PP pair<P,P>
#define Yes(f){cout<<(f?"Yes":"No")<<endl;}
#define YES(f){cout<<(f?"YES":"NO")<<endl;}

class MaxTriangle{

  public:
    double calculateArea(int A,int B){

     
      vector<P> v1,v2;

      for(int i=0;i*i<=A;i++){
        int j=A-i*i;
        //cout<<i<<' '<<j<<endl;
        if(isSquare(j)){
          v1.PB(P(i,sqrt(j)));
        }
      }

      for(int i=0;i*i<=B;i++){
        int j=B-i*i;
        if(isSquare(j)){
          v2.PB(P(i,sqrt(j)));
        }
      }

      

      double sum=-1.0;
      for(P p:v1){
        for(P q:v2){
          double x1=p.F,y1=p.S,x2=q.F,y2=q.S;
          double s=max(y1,y2)*(x1+x2);
          s-=x1*y1/2;
          s-=x2*y2/2;
          s-=(x1+x2)*abs(y1-y2)/2;
          sum=max(sum,s);
        }
      }

      return sum;

    }

    bool isSquare(int n){
      ll l=0,r=n+1;
      while(r-l>1){
        ll m=(r+l)/2;
        if(m*m>n) r=m;
        else l=m;
      }
      

      return (l*l==n);
    }

};

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int a,b;
  cin>>a>>b;
  MaxTriangle solve;
  cout<<solve.calculateArea(a,b)<<endl;


}
