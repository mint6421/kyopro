

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


vector<int> divisor(int n){
  vector<int> ret;
  for(int i=1;i*i<=n;i++){
    if(n%i==0){
      ret.PB(i);
      if(i*i!=n) ret.PB(n/i);
    }
  }

  sort(all(ret));

  return ret;
}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n;
  cin>>n;
  vi a(n);
  int s=0;
  rep(i,n){
    cin>>a[i];
    s+=a[i];
  }

  vi div = divisor(s);

  int ans=0;
  for(auto x:div){
    int sum=0;
    int p=s/x;
    bool flag=true;
    rep(i,n){
      sum+=a[i];
      if(sum>p) flag=false;
      if(sum==p) sum=0;
    }

    if(flag) ans=x;
    
  }

  cout<<ans<<endl;



}
