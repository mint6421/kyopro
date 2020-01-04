

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

  int n;
  cin>>n;
  vector<PP> v(n);
  rep(i,n){
    cin>>v[i].F.F>>v[i].F.S>>v[i].S.F;
    v[i].S.S=i;
  }
  sort(all(v));

  vector<P> ans;
  vector<PP> w;
  rep(i,v.size()){
    if(i+1<v.size()&&v[i].F.F==v[i+1].F.F&&v[i].F.S==v[i+1].F.S){
      ans.PB(P(v[i].S.S,v[i+1].S.S));
      i++;
    }else{
      w.PB(PP(P(v[i].F.S,v[i].S.F),P(v[i].F.F,v[i].S.S)));
    }
  }
  v=w;
  w.clear();
  sort(all(v));
  rep(i,v.size()){
    if(i+1<v.size()&&v[i].F.F==v[i+1].F.F&&v[i].F.S==v[i+1].F.S){
      ans.PB(P(v[i].S.S,v[i+1].S.S));
      i++;
    }else{
      w.PB(PP(P(v[i].F.S,v[i].S.F),P(v[i].F.F,v[i].S.S)));
    }
  }

  v=w;
  w.clear();
  sort(all(v));
  rep(i,v.size()){
    if(i+1<v.size()&&v[i].F.F==v[i+1].F.F&&v[i].F.S==v[i+1].F.S){
      ans.PB(P(v[i].S.S,v[i+1].S.S));
      i++;
    }else{
      w.PB(PP(P(v[i].F.S,v[i].S.F),P(v[i].F.F,v[i].S.S)));
    }
  }
  
  
  v=w;
  w.clear();
  sort(all(v));
  rep(i,v.size()){
    if(i+1<v.size()&&v[i].F.F==v[i+1].F.F){
      ans.PB(P(v[i].S.S,v[i+1].S.S));
      i++;
    }else{
      w.PB(PP(P(v[i].F.S,v[i].S.F),P(v[i].F.F,v[i].S.S)));
    }
  }
  
  v=w;
  w.clear();
  sort(all(v));
  rep(i,v.size()){
    if(i+1<v.size()&&v[i].F.F==v[i+1].F.F){
      ans.PB(P(v[i].S.S,v[i+1].S.S));
      i++;
    }else{
      w.PB(PP(P(v[i].F.S,v[i].S.F),P(v[i].F.F,v[i].S.S)));
    }
  }
  
  v=w;
  w.clear();
  sort(all(v));
  rep(i,v.size()){
    if(i+1<v.size()&&v[i].F.F==v[i+1].F.F){
      ans.PB(P(v[i].S.S,v[i+1].S.S));
      i++;
    }else{
      w.PB(PP(P(v[i].F.S,v[i].S.F),P(v[i].F.F,v[i].S.S)));
    }
  }
  
  v=w;
  sort(all(v));
  rep(i,v.size()){
    ans.PB(P(v[i].S.S,v[i+1].S.S));
    i++;
  }




  for(P p:ans){
    cout<<p.F+1<<' '<<p.S+1<<endl;
  }


}
