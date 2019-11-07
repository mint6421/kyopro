
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



vector< int > prime_table(int n) {
  vector< bool > prime(n + 1, true);
  vi res;
  if(n >= 0) prime[0] = false;
  if(n >= 1) prime[1] = false;
  for(int i = 2; i * i <= n; i++) {
    if(!prime[i]) continue;
    for(int j = i + i; j <= n; j += i) {
      prime[j] = false;
    }
  }

  rep(i,n+1){
    if(prime[i]) res.PB(i);
  }
  return res;
}




bool is_square(int n){
  ll l=0,r=(int)1e9;
  while(r-l>1){
    ll m=(r+l)/2;
    if(m*m>n) r=m;
    else l=m;
  }


  return (l*l==n);
}


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n;
  map<int,int> mp;
  vi prime=prime_table(2500);
  vi a,b;
  cin>>n;
  rep(i,n){
    int s;
    cin>>s;
    int t=1,u=1;

    for(int p:prime){
      int c=0;
      while(s%p==0){
        c++;
        s/=p;
      }
      
      c%=3;
      if(c==0) continue;
      if(c==1){
        t*=p;
        u*=p*p;
      }
      else{
        t*=p*p;
        u*=p;
      }
    }
    if(is_square(s)){      
      t*=s;
      u*=sqrt(s);
    }else{
      t*=s;
      u*=s*s;
    }

    //cout<<t<<' '<<u<<endl;
      
    a.PB(t);
    b.PB(u);
    mp[t]++;
  }

  int ans=0;

  rep(i,n){
    if(a[i]==1) continue;
    //cout<<a[i]<<' '<<b[i]<<endl;
    ans+=max(mp[a[i]],mp[b[i]]);
    //cout<<ans<<endl;
    mp[a[i]]=0;
    mp[b[i]]=0;
  }

  cout<<ans+!!mp[1]<<endl;
}
