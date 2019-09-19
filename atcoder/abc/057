
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


int c[1100][1100];

void comb_table(void){
  for(int i=0;i<=1000;i++){
    for(int j=0;j<=i;j++){
      if(j==0||j==i){
        c[i][j] = 1LL;
      }
      else{
        c[i][j]=(c[i-1][j-1]+c[i-1][j]);
      }
    }
  }
}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n,a,b;
  cin>>n>>a>>b;
  vi v(n);
  rep(i,n){
    cin>>v[i];
  }

  sort(all(v));
  reverse(all(v));

  int s=0,t=0;
  rep(i,n){
    if(v[i]==v[a-1]){
      s++;
      if(i<a) t++;
    }
  }

  double ave=0;
  rep(i,a){
    ave+=v[i];
  }

  ave/=a;
  comb_table();
  cout<<ave<<endl;
  int ans=0;
  if(a==t){
    FOR(i,a,b+1){
      ans+=c[s][i];
    }
  }else{
    ans=c[s][t];
  }

  cout<<ans<<endl;



}
