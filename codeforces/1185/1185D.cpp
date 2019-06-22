
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

void f(int r){
  vector<P> b;
  rep(i,n){
    if(i!=r) b.PB(v[i]);
  }

  if(b.size()>2){
    int d=b[1].F-b[0].F;
    rep(i,b.size()-1){
      if(b[i+1].F-b[i].F!=d) return;
    }
  }

  cout<<v[r].S+1<<endl;
  exit(0);
}

main(){
  cin>>n;
  v.resize(n);
  rep(i,n){
    cin>>v[i].F;
    v[i].S=i;
  }
  sort(all(v));

  f(0);
  f(n-1);

  int m=0;
  rep(i,n-1){
    m=max(m,v[i+1].F-v[i].F);

  }

  int c=0;
  rep(i,n-1){
    if(v[i+1].F-v[i].F!=m){
      f(i);
      f(i+1);
      c++;
      if(c>2)
        break;
    }
  }

  cout<<-1<<endl;
}
