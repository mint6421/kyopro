

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

int s[2100][2100];

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int n;
  cin>>n;
  string t;
  cin>>t;
  vi v(n+1,0);
  FOR(i,1,n+1){
    v[i]+=v[i-1];
    if(t[i-1]=='E') v[i]++;
  }

  vi a(n+1,0);
  FOR(i,1,n+1){
    cin>>a[i];
  
  }

  rep(i,n+1){
    FOR(j,i,n+1){
      s[i][j]=a[j];
      s[i][j]+=s[i][j-1];
    }
  }

  int q;
  cin>>q;
  while(q--){
    int k;
    cin>>k;
    int ans=0;
    rep(i,n+1){
      int l=i,r=n+1;
      while(r-l>1){
        int m=(r+l)/2;
        if(s[i][m]-s[i][i]>k) r=m;
        else l=m;
      }
      //cout<<' '<<l<<endl;
      //cout<<l<<' '<<i<<endl;
      ans=max(ans,v[l]-v[i]);
    }
    cout<<ans<<endl;
  }



}
