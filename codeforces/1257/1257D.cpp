

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
int Mplus(int x,int y) {return (x+y)%M;}
int Msub(int x,int y) {return (x-y+M)%M;}
int Mmul(int x,int y) {return (x*y)%M;}

int a[200010];
int b[200010];

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int q;
  cin>>q;
  while(q--){
    int n;
    cin>>n;
    rep(i,n){
      cin>>a[i];
    }
    rep(i,n+1) b[i]=0;

    int m;
    cin>>m; 
    rep(i,m){
      int p,x;
      cin>>p>>x;
      b[x]=max(b[x],p);
    }
    rrep(i,n-1) b[i]=max(b[i],b[i+1]);

    int it=0,ans=0;
    
    while(it<n){
      ans++;
      int c=0;
      int mx=0;
      while(true){
        mx=max(mx,a[it+c]);
        if(mx>b[c+1]) break;
        c++;
      }
      if(c==0){
        ans=-1;
        break;
      }
      it+=c;
    }
    cout<<ans<<endl;
  }
}
