

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

int m,n,k,t;
vi a;
vector<PI> v;


bool f(int x){

  int mi=a[x-1];
  vector<P> p;
  rep(i,k){
    if(v[i].S>mi){
      p.PB(v[i].F);
    }
  }
  sort(all(p));
  int res=0;
  int di=0;
  for(P s:p){
    if(s.F<=di){
      res+=max(0LL,s.S-di);
      di=max(di,s.S);
    }else{
      res+=s.S-s.F+1;
      di=s.S;
    }
  }

  res=2*res+n+1;

  return res<=t;
}
  


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  cin>>m>>n>>k>>t;
  a=vi(m);
  rep(i,m){
    cin>>a[i];
  }
  sort(all(a));
  reverse(all(a));
  v=vector<PI>(k);

  rep(i,k){
    cin>>v[i].F.F>>v[i].F.S>>v[i].S;
  }
  

  int l=0,r=m+1;
  while(r-l>1){
    int mi=(l+r)/2;
    if(f(mi)) l=mi;
    else r=mi;
  }

  cout<<l<<endl;


}
