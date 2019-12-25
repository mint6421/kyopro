

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


signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);


  int q;
  cin>>q;
  while(q--){
    int n;
    cin>>n;
    vi a(2*n);
    int s=0,t=0;
    rep(i,2*n){
      cin>>a[i];

      if(i<n){
        if(a[i]==1) s++;
        else s--;
      }else{
        if(a[i]==1) t--;
        else t++;
      }
    }

    vi v(2*n+1);
    FOR(i,n,2*n+1){
      int r=t+n;
      //cout<<' '<<r<<endl;
      if(v[r]==0) v[r]=i;
      if(i<2*n){
        if(a[i]==1) t++;
        else t--;
      }

    }

    int ans=2*n;
    RFOR(i,n-1,-1){
      int r=s+n;
      //cout<<r<<endl;
      if(v[r]){
        int x=v[r]-n;
        ans=min(ans,n-1-i+x);
        //cout<<n-1-i<<' '<<x<<endl;
      }
      if(i>=0){
        if(a[i]==1) s--;
        else s++;
      }
    }

    cout<<ans<<endl;

  }


}
