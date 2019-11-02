
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


class TheNewHouseDivOne{
  public:
    double distance(vector<int> x,vector<int> y,int k){

      double ans=inf;
      int n=x.size();
      for(double i=-500;i<=500;i++){
        for(double j=-500;j<=500;j++){
          vector<double> v;
          rep(l,n){
            v.PB(max(x[l]-j/10,j/10-x[l])+max(y[l]-i/10,i/10-y[l]));
          }
          sort(all(v));
          ans=min(ans,v[k-1]);
        }
      }
    
      
    return ans;

    }
};


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n,k;
  cin>>n>>k;
  vi x(n),y(n);
  rep(i,n){
    cin>>x[i]>>y[i];
  }

  TheNewHouseDivOne solve;

  cout<<solve.distance(x,y,k)<<endl;


}
