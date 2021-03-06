

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
    int n,t,a,b;
    cin>>n>>t>>a>>b;
    vector<P> v;
    vi h(n);
    int cnta=0,cntb=0;
    rep(i,n){
      cin>>h[i];
      if(h[i]) cntb++;
      else cnta++;
    }

    rep(i,n){
      int s;
      cin>>s;
      v.PB(P(s,h[i]));
    }

    v.PB(P(t+1,0));
    sort(all(v));

    int cnt1=0,cnt2=0;
    int ans=0;
    rep(i,n+1){
      int need=cnt1*a+cnt2*b;
      int has=v[i].F-1-need;
      if(has>=0){
        int cana=min(cnta-cnt1,has/a);
        cana=max(cana,0LL);
        has-=cana*a;
        int canb=min(cntb-cnt2,has/b);
        canb=max(canb,0LL);
        ans=max(ans,cnt1+cnt2+cana+canb);
      }
      int l=i;
      while(l<v.size()&&v[l].F==v[i].F){
        if(v[l].S){
          cnt2++;
        }else{
          cnt1++;
        }
        l++;
      }
      i=l-1;
    }
    cout<<ans<<endl;
  }
  


}
