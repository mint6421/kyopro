
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
vector<P> v;

bool f(int k){

  rep(i,n){
    if(v[i].F%k!=0&&v[i].S%k!=0) return false;
  }
  return true;
}


main(){
  cin>>n;
  v.resize(n);
  
  rep(i,n){
    cin>>v[i].F>>v[i].S;
  }

  vector<int> res;
  int x=v[0].F;
  int y=v[0].S;

  for(int i=1;i*i<=x;i++){
    if(x%i==0){
      res.PB(i);
      if(i*i!=x)
        res.PB(x/i);
    }
  }
  for(int i=1;i*i<=y;i++){
    if(y%i==0){
      if(find(all(res),i)==res.end()) res.PB(i);
      if(i*i!=y){
        if(find(all(res),y/i)==res.end()) res.PB(y/i);
      }
    }
  }

  sort(all(res));
  reverse(all(res));

  rep(i,res.size()){
    if(f(res[i])){
      cout<<res[i]<<endl;
      break;
    }
  }

}
