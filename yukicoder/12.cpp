

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



vector< bool > prime_table(int n) {
  vector< bool > prime(n + 1, true);
  if(n >= 0) prime[0] = false;
  if(n >= 1) prime[1] = false;
  for(int i = 2; i * i <= n; i++) {
    if(!prime[i]) continue;
    for(int j = i + i; j <= n; j += i) {
      prime[j] = false;
    }
  }
  return prime;
}


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n;
  cin>>n;
  bool b[10]={};
  rep(i,n){
    int a;
    cin>>a;
    b[a]=true;
  }

  vector<bool> prime=prime_table(5000001);
  int l=1,r=1;
  int ans=-1;
  bool cnt[10]={};
  while(r<=5000000){
    /*
    cout<<l<<' '<<r<<endl;
    rep(i,10){
      cout<<cnt[i]<<' ';
    }
    cout<<endl;
    */

    if(prime[r]){
      int s=r;
      
      while(s){
        cnt[s%10]=true;
        s/=10;
      }
    }
    bool flag=true;
    rep(i,10){
      flag&=!(b[i]^cnt[i]);
    }
    if(flag){
      ans=max(ans,r-l);
      r++;
    }else{
      flag=false;
      rep(i,10){
        flag|=((!b[i])&cnt[i]);
      }
      if(!flag){
        r++;
      }else{
        r++;
        l=r;
        rep(i,10) cnt[i]=0;
      }
    }

  }        

  cout<<ans<<endl;

}
