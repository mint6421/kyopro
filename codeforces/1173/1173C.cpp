
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


main(){
  int n;
  int a[210000],b[210000],p[210000];

  cin>>n;

  FOR(i,1,n+1){
    cin>>a[i];
    p[a[i]]=0;
  }
  FOR(i,1,n+1){
    cin>>b[i];
    p[b[i]]=i;
  }

  if(p[1]){
    int i;
    for(i=2;p[i]==p[1]+i-1;i++);
    if(p[i-1]==n){
      int j;
      for(j=i;j<=n&&p[j]<=j-i;j++);
      if(j>n){
        cout<<n-i+1<<endl;
        return 0;
      }
    }
  }

  int ans=-1;
  FOR(i,1,n+1){
    ans=max(ans,p[i]-i+1+n);
  }

  cout<<ans<<endl;
}
