

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


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n,k;
  cin>>n>>k;
  vi a(n);
  rep(i,n){
    cin>>a[i];
  }

  int i=0,j=0;
  int s=0;
  vi cnt(1e5+1,0);
  int ans=inf;

  while(i<n){
    while(i<n&&s<k){
      if(a[i]<=k&&cnt[a[i]]==0) s++;
      cnt[a[i]]++;
      i++; 
    }
    
    if(s==k)ans=min(ans,i-j);
    while(s==k){
      cnt[a[j]]--;
      if(a[j]<=k&&cnt[a[j]]==0) s--;
      j++;
      if(s==k)ans=min(ans,i-j);
    }
  }

  cout<<(ans==inf?0:ans)<<endl;

    
}
