
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

int n,l,q;
int x[110000],d[20][110000];

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  cin>>n;
  rep(i,n){
    cin>>x[i];
  }
  cin>>l>>q;
  int p=0;
  rep(i,n){
    while(x[i]-x[p]>l) p++;
    d[0][i]=p;
  }
  FOR(i,1,17){
    rep(j,n+1){
      d[i][j]=d[i-1][d[i-1][j]];
    }
  }

  while(q--){
    int a,b;
    cin>>a>>b;
    a--;b--;
    if(a==b){
      cout<<0<<endl;
    }else{
      if(a>b) swap(a,b);
      int res=1;
      rrep(i,16){
        if(d[i][b]>a){
          res+=1<<i;
          b=d[i][b];
        }
      }
      cout<<res<<endl;
    }
  }


}
