
#include<bits/stdc++.h>
using namespace std;
#define inf 1000000000
#define INF 1000000000000000
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
void init(){
  cin.tie(0);
  ios::sync_with_stdio(false);
}
int n;
int v[610000];
map<int,int> mp;
vector<P> ans;

void f(int a,int b){
  swap(v[a],v[b]);
  mp[v[b]]=b;
  mp[v[a]]=a;

}

main(){
  init();

  cin>>n;

  FOR(i,1,n+1){
    cin>>v[i];
    mp[v[i]]=i;
  }


  FOR(i,1,n+1){
    if(v[i]==i) continue; 
    int k=mp[i];
    //cout<<mp[i]<<' '<<i<<endl;

    if(abs(k-i)*2>=n){
      ans.PB(P(i,k));
      f(i,k);
    }else{
      if(i<=n/2&&k<=n/2){
        ans.PB(P(k,n));
        ans.PB(P(i,n));
        ans.PB(P(k,n));
        f(i,mp[i]);
      }else if(i>n/2&&k>n/2){
        ans.PB(P(1,k));
        ans.PB(P(1,i));
        ans.PB(P(1,k));
        f(i,mp[i]);
      }else{
        if(k>n/2){
          ans.PB(P(1,k));
          ans.PB(P(1,n));
          ans.PB(P(i,n));
          ans.PB(P(1,k));
          f(mp[i],n);
          f(i,mp[i]);
        }else{
          ans.PB(P(1,i));
          ans.PB(P(1,n));
          ans.PB(P(k,n));
          ans.PB(P(1,i));
          f(1,mp[i]);
          f(i,mp[i]);
        }
      }
    }
  }

  

  cout<<ans.size()<<endl;
  rep(i,ans.size()){
    cout<<ans[i].F<<' '<<ans[i].S<<endl;
  }

}
