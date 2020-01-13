

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

  int x;
  cin>>x;
  vi div = divisor(x);
  int ax=INF,bx=INF;

  for(int a:div){
    int b=x/a;
    if(a>b) break;
    if(x==a*b/__gcd(a,b)){
      //cout<<a*b/__gcd(a,b)<<endl;
      //cout<<a<<' '<<b<<endl;
      if(bx>b){
        ax=a;
        bx=b;
      }
    }
  }

  cout<<ax<<' '<<bx<<endl;
     

}
