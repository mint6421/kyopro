
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
    vi v;
    int a=0,b=0;
    rep(i,n){
      string s;
      cin>>s;
      rep(j,s.size()){
        if(s[j]=='0') a++;
        else b++;
      }
      v.PB(s.size());
    }
    sort(all(v));
    int ans=0;

    rep(i,n){
      if(v[i]%2){
        if(b==0||a%2){
          v[i]--;
          a--;
        }else{
          v[i]--;
          b--;
        }
      }
      ans++;
      if(i==n-1&&a%2&&b%2) ans--;
      if(a>=v[i]) a-=v[i];
      else if(b>=v[i]) b-=v[i];
    }
    cout<<ans<<endl;
  }
}
