
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
#define Yes(f){cout<<(f?"Yes":"No")<<endl;}
#define YES(f){cout<<(f?"YES":"NO")<<endl;}


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int a,b;
  cin>>a>>b;

  if(a>b) swap(a,b);

  vi resa,resb;
  for(int i=1;i*i<=a;i++){
    if(a%i==0){
      resa.PB(i);
      if(i*i!=a) resa.PB(a/i);
    }
  }


  for(int i=1;i*i<=b;i++){
    if(b%i==0){
      resb.PB(i);
      if(i*i!=b) resb.PB(b/i);
    }
  }

    vi res;
  sort(all(resa));
  sort(all(resb));

  for(int x:resa){
    for(int y:resb){
      //cout<<x<<' '<<y<<endl;
      if(x==y) res.PB(x);
    }
  }

    vi ans;
  for(int x:res){
    bool flag=true;
    for(int y:ans){
      if(__gcd(x,y)!=1) flag=false;
    }
    if(flag) ans.PB(x);
  }

  cout<<ans.size()<<endl;
  

}
