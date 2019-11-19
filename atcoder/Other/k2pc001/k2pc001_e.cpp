

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



int square(int n){
  ll l=0,r=(int)1e9;
  while(r-l>1){
    ll m=(r+l)/2;
    if(m*m>n) r=m;
    else l=m;
  }


  return l;
}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n;
  cin>>n;
  int m=square(n);
  if(n==2){
    cout<<0<<endl;
  }else if(m*m!=n){
    cout<<-1<<endl;
  }else{
    int ans=n-1;
    //cout<<ans<<endl;
    m--;
    n=m*m;
    while(m>=2){
      //cout<<ans<<endl;
      ans+=n-m;
      m--;
      n=m*m;
    }
    cout<<ans<<endl;
  }


}
