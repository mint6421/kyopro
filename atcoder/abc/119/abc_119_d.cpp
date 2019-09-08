
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


int a,b,q;

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

 
  
  int a,b,q;
  cin>>a>>b>>q;
  set<int> sl,sr,tl,tr;
  
 
  rep(i,a){
    int x;
    cin>>x;
    sr.insert(x);
    sl.insert(-x);
  }
  rep(i,b){
    int x;
    cin>>x;
    tr.insert(x);
    tl.insert(-x);
  }
 

  while(q--){
    int x;
    cin>>x;
    auto srn=sr.lower_bound(x);
    auto sln=sl.lower_bound(-x);
    auto trn=tr.lower_bound(x);
    auto tln=tl.lower_bound(-x);
    int ans=INF;
    //cout<<srn<<' '<<sln<<' '<<trn<<' '<<tln<<endl;
    if(srn!=sr.end()&&trn!=tr.end())ans=min(ans,max(*srn,*trn)-x);
    //cout<<ans<<endl;
    if(sln!=sl.end()&&tln!=tl.end())ans=min(ans,x-min(-*sln,-*tln));
    //cout<<sln<<' '<<tln<<endl;
    //cout<<ans<<endl;
    if(srn!=sr.end()&&tln!=tl.end())ans=min(ans,*srn+*tln+min(*srn-x,x+*tln));
    //cout<<ans<<endl;
    if(trn!=tr.end()&&sln!=sl.end())ans=min(ans,*trn+*sln+min(*trn-x,x+*sln));
    cout<<ans<<endl;

  }



}
