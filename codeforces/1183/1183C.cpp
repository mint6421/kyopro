
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



main(){
  int q;
  cin>>q;

  while(q--){
    int k,n,a,b;
    cin>>k>>n>>a>>b;
    if(k-b*n<=0){
      cout<<-1<<endl;
      continue;
    }

    int l=0,r=n+1;
    while(r-l>1){
      //cout<<r<<' '<<l<<' '<<n<<endl;
      int m=(r+l)/2;
      int s=n-m;
      if(k-a*m-b*s<=0) r=m;
      else l=m;
    }

    cout<<l<<endl;
  }

}
