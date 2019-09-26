
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
#define IP pair<int,P>
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
    vi a(n);
    rep(i,n){
      cin>>a[i];
    }
    bool flag=true;
    bool ans=false;
    while(flag){
      flag=false;
      rep(i,a.size()){
        if(a[i]==2048) ans=true;
      }
      if(ans) break;
      vi b;
      sort(all(a));
      rep(i,a.size()){
        if(i<a.size()-1&&a[i]==a[i+1]){
          b.PB(a[i]*2);
          i++;
          flag=true;
        }else{
          b.PB(a[i]);
        }
      }
      a=b;
    }
    YES(ans);
  }

}
