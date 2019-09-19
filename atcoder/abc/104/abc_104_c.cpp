
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

int d,g;
int p[11],c[11];

int f(int k){
  int sum=0;
  int res=0;
  int t=-1;
  rep(i,d){
    if(k&(1<<i)){
      sum+=p[i]*100*(i+1);
      sum+=c[i];
      res+=p[i];
    }else{
      t=i;
    }
  }

  //cout<<k<<' '<<sum<<' '<<t<<endl;

  if(sum+p[t]*100*(t+1)<g) return INF;

  if(sum>=g) return res;

  return res+(g-sum+100*(t+1)-1)/(100*(t+1));

}


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  cin>>d>>g;
  rep(i,d){
    cin>>p[i]>>c[i];
  }

  int ans=INF;

  rep(i,1<<d){
    ans=min(ans,f(i));
  }

  cout<<ans<<endl;


}
