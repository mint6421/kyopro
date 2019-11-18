

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

int n;
vector<double> x,y;
double ave=0;
double m;

void f(vi v,bool b[10]){
  if(v.size()==n){
    double sum=0;
    FOR(i,1,n){
      sum+=sqrt((x[i]-x[i-1])*(x[i]-x[i-1])+(y[i]-y[i-1])*(y[i]-y[i-1]));
    }
    ave+=sum;
    m++;
  }

  rep(i,n){
    if(!b[i]){
      b[i]=true;
      v.PB(i);
      f(v,b);
      b[i]=false;
      v.erase(v.end()-1);
    }
  }
}



signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  cin>>n;
  x=vector<double>(n);
  y=vector<double>(n);
  rep(i,n){
    cin>>x[i]>>y[i];
  }

  double sum=0;
  double m=1;
  FOR(i,1,n+1) m*=i;
  double k=1;
  FOR(i,1,n) k*=i;

  rep(i,n){
    FOR(j,i+1,n){
      double res=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
      res*=2*k;
      sum+=res;
    }
  }

  cout<<sum/m<<endl;
}

