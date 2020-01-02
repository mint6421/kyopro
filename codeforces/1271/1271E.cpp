

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

int n,k;

bool f(int m){
  int l=m,r=m,res=0;
  while(l<=n){
    if(r<n) res+=r-l+1;
    else if(l<=n&&n<=r) res+=n-l+1;
    l*=2;
    r=r*2+1;
  }

  if(m%2==0){
    l=m+1;r=m+1;
    while(l<=n){
      if(r<n) res+=r-l+1;
      else if(l<=n&&n<=r) res+=n-l+1;
      l*=2;
      r=r*2+1;
    }
  }

  
  return res>=k;
}
  
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);


  cin>>n>>k;
  int l=0,r=n/2+1;
  
  while(r-l>1){
    int m=(r+l)/2;
    if(f(m*2)) l=m;
    else r=m;
  }

  int res=l*2;
  l=0,r=n/2+1;
  while(r-l>1){
    int m=(l+r)/2;
    if(f(m*2+1)) l=m;
    else r=m;
  }

  cout<<max(res,l*2+1)<<endl;
  

}
