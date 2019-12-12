

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


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n,w;
  cin>>n>>w;
  vector<P> v(n);
  rep(i,n){
    cin>>v[i].F>>v[i].S;
  }

  map<int,int> mp1,mp2;
  rep(bit,(1<<(n/2))){
    P p=P(0,0);
    rep(i,n/2){
      if(bit&(1<<i)){
        p=P(p.F+v[i].F,p.S+v[i].S);
      }
    }
    //cout<<bit<<' '<<p.F<<' '<<p.S<<endl;
    if(mp1.find(p.S)==mp1.end()){
      mp1[p.S]=p.F;
    }else{
      mp1[p.S]=max(mp1[p.S],p.F);
    }
  }

  int p=0;
  for(auto m:mp1){
    p=max(p,m.S);
    mp1[m.F]=max(m.S,p);
  }

  rep(bit,(1<<(n/2+n%2))){
    P p=P(0,0);
    rep(i,n/2+n%2){
      if(bit&(1<<i)){
        p=P(p.F+v[i+n/2].F,p.S+v[i+n/2].S);
      }
    }
    if(mp2.find(p.S)==mp2.end()){
      mp2[p.S]=p.F;
    }else{
      mp2[p.S]=max(mp2[p.S],p.F);
    }
  }

  p=0;
  for(P m:mp2){
    p=max(p,m.S);
    mp2[m.F]=max(m.S,p);
  }
  int ans=0;
  for(P m:mp1){ 
    auto it=mp2.lower_bound(w-m.F+1);
    if(it==mp2.begin()) continue;
    it--;
    ans=max(ans,m.S+it->S);
  }
  
  cout<<ans<<endl;

}
