
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
void init(){
  cin.tie(0);
  ios::sync_with_stdio(false);
}

int n,m,ta,tb,k;

main(){
  cin>>n>>m>>ta>>tb>>k;

  vector<int> a(n);
  rep(i,n){
    cin>>a[i];
  }
  vector<int> b(m);
  rep(i,m){
    cin>>b[i];
  }
  b.PB(INF);

  vector<P> v;
  int j=0;
  rep(i,n){
    while(a[i]+ta>b[j]) j++;
    v.PB(P(i,j));
  }

  if(k>=n){
    cout<<-1<<endl;
    return 0;
  }
  
  int ans=-1;
  rep(i,k+1){
    int r=v[i].S+k-i;
    //cout<<v[i].S<<' '<<r<<endl;
    if(r>=m){
      ans=-1;
      break;
    }
    ans=max(ans,b[r]+tb);
  }

  cout<<ans<<endl;

}
