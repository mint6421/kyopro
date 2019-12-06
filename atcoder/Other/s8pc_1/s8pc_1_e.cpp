

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
int Madd(int x,int y) {return (x+y)%M;}
int Msub(int x,int y) {return (x-y+M)%M;}
int Mmul(int x,int y) {return (x*y)%M;}



ll power(ll x,ll k){
  ll ret=1;
  while(k>0){
    if(k&1) (ret*=x) %= M;
    (x*=x) %= M;
    k >>= 1;
  }
  return ret;
}


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n,q;
  cin>>n>>q;
  vi a(n+10);
  rep(i,n){
    cin>>a[i];
  }

  vi dist(n+10,0);
  rep(i,n-1){
    dist[i+1]=power(a[i],a[i+1]);
  }

  vi rdist(n+10,0);
  rep(i,n-1){
    rdist[i]=dist[i+1];
    //cout<<rdist[i]<<endl;
  }

  FOR(i,1,n){
    dist[i+1]=Madd(dist[i+1],dist[i]);
  }

  rrep(i,n-2){
    rdist[i]=Madd(rdist[i],rdist[i+1]);
    //cout<<rdist[i]<<endl;
  }

  vi query;
  query.PB(0);
  rep(i,q){
    int x;
    cin>>x;
    x--;
    query.PB(x);
  }
  query.PB(0);

  int ans=0;
  FOR(i,1,query.size()){
    int x=query[i],p=query[i-1];
    if(x>p){
      ans=Madd(ans,Msub(dist[x],dist[p]));
    }else{
      ans=Madd(ans,Msub(rdist[x],rdist[p]));
    }
    //cout<<p<<' '<<x<<endl;
    //cout<<ans<<endl;
  }

  cout<<ans<<endl;

  

}
