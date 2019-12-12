

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

map<int,int> f(map<int,int> a,map<int,int> b){
  map<int,int> res;
  for(P ma:a){
    for(P mb:b){
      
      res[ma.F+mb.F]+=ma.S*mb.S;
    }
  }

  return res;
}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n,v;
  cin>>n>>v;
  map<int,int> mpa,mpb,mpc,mpd;
  rep(i,n){
    int a;
    cin>>a;
    mpa[a]++;
  }
  rep(i,n){
    int a;
    cin>>a;
    mpb[a]++;
  }
  rep(i,n){
    int a;
    cin>>a;
    mpc[a]++;
  }
  rep(i,n){
    int a;
    cin>>a;
    mpd[a]++;
  }

  auto mpab=f(mpa,mpb);
  auto mpcd=f(mpc,mpd);

  int ans=0;
  for(auto m:mpab){
    //cout<<m.F<<' '<<m.S<<endl;
    if(mpcd.find(v-m.F)==mpcd.end()) continue;
    ans+=m.S*mpcd[v-m.F];
  }

  cout<<ans<<endl;

}
