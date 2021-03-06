

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



int fac[2110000];

int inv(int x){
  if(x==1) return 1;
  return (M-M/x)*inv(M%x)%M;
}


int comb(int n,int k){
  int x=(fac[k]*fac[n-k])%M;
  return (fac[n]*inv(x))%M;
}

int fac_init(int n){
  fac[0]=1;
  FOR(i,1,n+1){
    fac[i]=fac[i-1]*i;
    fac[i]%=M;
  }
}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int x,y;
  cin>>x>>y;

  if((x+y)%3){
    cout<<0<<endl;
    return 0;
  }
  fac_init(2100000);

  int m=(x+y)/3;
  int ans=0;
  rep(i,m+1){
    int j=m-i;
    if(i*2+j==x&&i+j*2==y){
      ans+=comb(m,i);
      ans%=M;
    }
  }

  cout<<ans<<endl;



}
