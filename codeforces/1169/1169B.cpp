
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

int n,m;
vector<P> v;

bool g(int a,int b){
  rep(i,m){
    if(!(v[i].F==a||v[i].F==b||v[i].S==a||v[i].S==b)) return false;
  }

  return true;
}

bool f(int a){
  int b=-1,c=-1;

  rep(i,m){
    if(v[i].F==a||v[i].S==a) continue;
    b=v[i].F;
    c=v[i].S;
  }


  return (g(a,b)||g(a,c));
}


main(){
  
  cin>>n>>m;
  v.resize(m);
  rep(i,m){
    cin>>v[i].F>>v[i].S;
  }
  sort(all(v));
  if(f(v[0].F)||f(v[0].S)){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }


}
