
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
#define PI 3.14159265
#define F first
#define S second
#define PB push_back
#define EB emplace_back
#define int ll
#define vi vector<int>


int a[500010];
int sum[750][750];
int k=750;

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int q;
  cin>>q;
  while(q--){
    int t,x,y;
    cin>>t>>x>>y;
    if(t==1){
      a[x]+=y;
      FOR(i,1,k){
        sum[i][x%i]+=y;
      }
    }else{
      if(x>=k){
        int ans=0;
        for(int i=y;i<=500000;i+=x){
          ans+=a[i];
        }
        cout<<ans<<endl;
      }else{
        cout<<sum[x][y]<<endl;
      }
    }
  }

}
