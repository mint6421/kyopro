
#include<bits/stdc++.h>
using namespace std;
#define inf 1000000000
#define INF 1000000000000000
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
void init(){
  cin.tie(0);
  ios::sync_with_stdio(false);
}


ull e[210000];
ull n;
ull x;
ull a[210000];
ull ans=ULLONG_MAX;


main(){
  cin>>n>>x;
  rep(i,n){
    cin>>a[i];
  }

  rrep(i,n){
    e[i]+=a[i]+e[i+1];
    //cout<<e[i]<<' ';
  }
  //cout<<endl;

  FOR(k,1,n+1){
    ull res=0;
    int j=1;
    for(int i=n;i>=0;i-=k){
      if(j==1){
        res+=5*(e[max(0LL,i-k)]-e[i]);
      }else{
        res+=(2*j+1)*(e[max(0LL,i-k)]-e[i]);
      }
      j++;
    }
    //cout<<res<<endl;
    ans=min(ans,k*x+res);
  }

  cout<<n*x+ans<<endl;
}
