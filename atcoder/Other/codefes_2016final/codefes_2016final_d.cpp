
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

map<int,int> a;
map<int,int> mul;
map<int,int> one;

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n,m;
  cin>>n>>m;
  rep(i,n){
    int x;
    cin>>x;
    a[x]++;
  }
  for(P x:a){
    mul[x.F%m]+=x.S/2;
    one[x.F%m]+=x.S%2;
    //cout<<x.F<<' ';
  }
  //cout<<endl;

  int ans=0;
  for(P p:one){
    int x=p.F,y=p.S;
    //cout<<x<<' '<<y<<' '<<endl;
    if(x==0||x==m-x){
      ans+=y/2;
    }else{
      int res=min(y,one[m-x]);
      ans+=res;
      //cout<<res<<' '<<y<<' '<<one[m-x]<<endl;
      y-=res;
      one[x]-=res;
      one[m-x]-=res;
      //cout<<one[x]<<' '<<one[m-x]<<endl;
      //cout<<x<<' '<<y<<endl;
      if(y>0){
        res=min(y,mul[m-x]*2);
        //cout<<res<<endl;
        ans+=res;
        one[x]-=res;
        mul[m-x]-=(res+1)/2;
      }
    }
    //cout<<ans<<endl;
  }

  for(P p:mul){
    //cout<<p.F<<' '<<p.S<<endl;
    ans+=p.S;
  }

  cout<<ans<<endl;

}
