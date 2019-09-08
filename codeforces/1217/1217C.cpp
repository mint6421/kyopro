
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

int nxt[300100];

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);

  int t;
  cin>>t;

  while(t--){
    string s;
    cin>>s;
    rep(i,s.size()){
      if(s[i]=='1') nxt[i]=i;
      else nxt[i]=(i==0?-1:nxt[i-1]);
    }
    int res=0;
    rep(r,s.size()){
      int sum=0;
      for(int l=r;l>=0&&r-l<20;l--){
        if(s[l]=='0') continue;
        sum+=1<<(r-l);
        if(sum<=r-(l==0?-1:nxt[l-1])) res++;
      }
    }
    cout<<res<<endl;
  }


}
